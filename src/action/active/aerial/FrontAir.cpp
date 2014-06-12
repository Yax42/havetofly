//
// FrontAir.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 20:38:01 2013 Brunier Jean
// Last update Mon May 06 22:33:21 2013 Brunier Jean
//

#include "FrontAir.hh"
#include "Game.hh"

const float				FrontAir::Power = 15;

FrontAir::FrontAir(Player &player) :
	AAction(player, UP_AIR, new Hit(60, Position(Power, Power), player.orient(), 15, false, Hit::ORIENT))
{
	_hit->add(30, Position(), _bones[Bones::HEAD]);
}

void	FrontAir::init(int v)
{
	_hit->reset();
	_hit->sleep(false);
	_count = 45;
}

bool	FrontAir::allow(int a)
{
	return (a == GRAVITY || a == INERTIE);
}

void	FrontAir::step()
{
	_count--;
	if (_count == 0)
		_player.engageAction(INERTIE);
}

void		FrontAir::check()
{
}

bool		FrontAir::request()
{
	return _player.key.getKeyDown(Key::HOR2) == _player.orient();
}

int			FrontAir::val()
{
	return 0;
}

void		FrontAir::upBones()
{
	_bones.set(20, -125, 13, -120, 20, 130, 25, 120, -90, _count* (16.0));
}

void		FrontAir::print(Graphics &g) const
{
	if (0 && _count > 0)
	{
		for (int i = 0; i < 4; i++)
			g.sponge(_bones[Bones::HEAD], i + 60, 6, 3, Angle(MTIME * 3, 0), 0);
	}
}