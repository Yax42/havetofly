//
// HitWall.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 01:08:34 2013 Brunier Jean
// Last update Fri Apr 12 12:25:05 2013 Brunier Jean
//

#include "HitWall.hh"
#include "Player.hh"

HitWall(const Player &player) : PassiveAction(player)
{
}

HitWall::~HitWall()
{
}

void		HitWall::check()
{
  if (player(WALL) && player.stun())
    {
      if (action(A_TECH).init())
	player = Position();
      else
	player.x(player.x() * (-1.2));
    }
}
