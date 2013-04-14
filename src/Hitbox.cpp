//
// Hitbox.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 15:41:09 2013 Brunier Jean
// Last update Sat Apr 13 19:54:42 2013 Brunier Jean
//

#include "Hitbox.hh"

Hitbox::Hitbox(const Position &topL, const Position &botR, const Position &center) :
	_topL(topL), _botR(botR), _center(center)
{
}

Hitbox::~Hitbox()
{
}

bool		Hitbox::touch(const Hitbox &other) const
{
  Position	topL1(_topL + _center);
  Position	botR1(_botR + _center);
  Position	topL2(other._topL + other._center);
  Position	botR2(other._botR + other._center);

  if (topL1.yDist() < botR2.yDist() || topL2.yDist() < botR1.yDist() ||
      topL1.xDist() < botR2.xDist() || topL2.xDist() < botR1.xDist())
    return (false);
  return (true);
}
