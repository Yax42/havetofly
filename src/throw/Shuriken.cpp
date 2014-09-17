//
// Shuriken.cpp for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 23 11:09:14 2013 Brunier Jean
// Last update Mon May 06 17:47:50 2013 Brunier Jean
//

#include "Shuriken.hh"
Color		getColorFromLevel(int level);

Shuriken::Shuriken(Player &player, const Position &pos, const Position &speed, int level) :
AThrowable(pos, speed, 40, Position(1, 1), player, Hit::NONE, true), _level(level)
{
	_speed = speed;
	_hit.add(12, Position(), _pos);
	_hit.sleep(0);
}

void		Shuriken::move()
{
}

void		Shuriken::print(Graphics &g) const
{
	g.sponge(_pos, 8, 6, 3, Angle(MTIME * 8, 0), getColorFromLevel(_level));
	g.sponge(_pos, 7, 6, 3, Angle(MTIME * 8, 0), getColorFromLevel(_level));
	g.sponge(_pos, 5, 6, 3, Angle(MTIME * 8, 0), getColorFromLevel(_level));
}

void		Shuriken::effect(Player &p)
{
	if (!p[IAction::TECH]->val())
		p.hit(&_hit);
	_alive = false;
}