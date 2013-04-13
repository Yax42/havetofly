//
// Hitbox.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 15:41:09 2013 Brunier Jean
// Last update Fri Apr 12 22:39:13 2013 Brunier Jean
//

#include "Hitbox.hh"
Hitbox(const Position &topL, const Position &botR, const Position &center) :
	_topL(topL), _botR(botR), _center(center)
{
}

~Hitbox()
{
}

bool		touch(const Hitbox &other) const
{
  Position	topL1(_topL + center);
  Position	botR1(_botR + center);
  Position	topL2(other._topL + other.center);
  Position	botR2(other._botR + other.center);

  if (topL1.y < botR2.y || topL2.y < botR1.y ||
      topL1.x < botR2.x || topL2.x < botR1.x)
    return (false);
  return (true);
}
