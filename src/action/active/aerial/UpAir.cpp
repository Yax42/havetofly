//
// UpAir.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 20:38:01 2013 Brunier Jean
// Last update Mon May 06 22:33:21 2013 Brunier Jean
//

#include "UpAir.hh"
#include "Game.hh"

const float				UpAir::Power = 15;

UpAir::UpAir(Player &player) :
	AAction(player, UP_AIR, new Hit(60, Position(0, Power), player.orient(), 15, false, Hit::ORIENT))
{
	_hit->add(24, Position(), _bones[Bones::FOOT1]);
	_hit->add(24, Position(), _bones[Bones::FOOT2]);
}

void	UpAir::init(int v)
{
	_hit->reset();
	_hit->sleep(false);
	_count = 45;
	_hit->setSpeed(Position(0, Power));
}

bool	UpAir::allow(int a)
{
	return (a == GRAVITY || a == INERTIE);
}

void	UpAir::step()
{
	_count--;
	if (_count >= 30)
	{
		_hit->setSpeed(Position(0, Power));
	}
	else if (_count >= 15)
	{
		_hit->setSpeed(Position(Power, 0));
	}
	else
	{
		_hit->setSpeed(Position(0, -Power));
	}

	if (_count == 0)
		_player.engageAction(INERTIE);
}

void		UpAir::check()
{
}

bool		UpAir::request()
{
	return _player.key.getKeyDown(Key::VERT2) == -1;
}

int			UpAir::val()
{
	return 0;
}

void		UpAir::upBones()
{
	_bones.angle[Bones::FOOT1] = Angle(10, 0);
	_bones.angle[Bones::FOOT2] = Angle(-5, 0);
	_bones.angle[Bones::KNEE1] = Angle(10, 0);
	_bones.angle[Bones::KNEE2] = Angle(5, 0);

	_bones.angle[Bones::HAND1] = Angle(0, 0);
	_bones.angle[Bones::HAND2] = Angle(0, 0);
	_bones.angle[Bones::ELBOW1] = Angle(0, 0);
	_bones.angle[Bones::ELBOW2] = Angle(0, 0);

	_bones.angle[Bones::HEAD] = Angle(0, 0);
	_bones.angle[Bones::BODY] = Angle(30 + 260 * _count / 45, 0);
}

void		UpAir::print(Graphics &g) const
{
}