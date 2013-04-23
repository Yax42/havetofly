//
// Shuriken.cpp for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 23 11:09:14 2013 Brunier Jean
// Last update Tue Apr 23 18:53:49 2013 Brunier Jean
//

#include "Shuriken.hh"

Shuriken::Shuriken(const Player &player) :
	AThrowable(player.pos(),
	player.closePos(),
	  30, Position(1, 1), player)
{
  _speed = RatioPosition(_speed.angle().betweenX(Angle(30, 0), _player.orient()), 7);
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
