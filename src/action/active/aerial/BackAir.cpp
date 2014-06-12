//
// BackAir.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 20:38:01 2013 Brunier Jean
// Last update Mon May 06 22:33:21 2013 Brunier Jean
//

#include "BackAir.hh"
#include "Game.hh"

const float				BackAir::Power = 15;

BackAir::BackAir(Player &player) :
	AAction(player, UP_AIR, new Hit(60, Position(0, Power), player.orient(), 15, false, Hit::ORIENT))
{
	_hit->add(14, Position(), _bones[Bones::FOOT1]);
	_hit->add(14, Position(), _bones[Bones::FOOT2]);
}

void	BackAir::init(int v)
{
	_hit->reset();
	_hit->sleep(false);
	_count = 45;
}

bool	BackAir::allow(int a)
{
	return (a == GRAVITY || a == INERTIE);
}

void	BackAir::step()
{
	_count--;
	if (_count == 0)
		_player.engageAction(INERTIE);
}

void		BackAir::check()
{
}

bool		BackAir::request()
{
	return _player.key.getKeyDown(Key::HOR2) == -_player.orient();
}

int			BackAir::val()
{
	return 0;
}

void		BackAir::upBones()
{
	_bones.set(-90, _count * 8, -90, 180 + _count * 8, 125, -45, -125, -45, 0, 0);
}

void		BackAir::print(Graphics &g) const
{
}