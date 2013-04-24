//
// Shuriken.cpp for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 23 11:09:14 2013 Brunier Jean
// Last update Wed Apr 24 09:52:06 2013 Brunier Jean
//

#include "Shuriken.hh"

Shuriken::Shuriken(const Player &player) :
	AThrowable(player.pos(),
	player.closePos(),
	  60, Position(1, 1), player, Hit::NONE)
{
  _speed = RatioPosition(_speed.angle().betweenX(Angle(35, 0), _player.orient()), 7);
  _hit.add(12, Position(), _pos);
}

void		Shuriken::move()
{
}

void		Shuriken::print(Graphics &g) const
{
  g.sponge(_pos, 8, 6, 3, Angle(MTIME * 8, 0), 0);
  g.sponge(_pos, 5, 6, 3, Angle(MTIME * 8, 0), 0);
}

void		Shuriken::effect(Player &)
{
  //p[IAction::DOUBLE_JUMP]->set(1);
  //p[IAction::UP_PUNCH]->set();
  //p[IAction::SHIELD]->set();
  //p[IAction::HOR_DASH]->set();
}
