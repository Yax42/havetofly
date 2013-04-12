//
// Inertie.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 11:31:46 2013 Brunier Jean
// Last update Fri Apr 12 13:28:55 2013 Brunier Jean
//

#include "Inertie.hh"

Inertie(const Player &player) : PassiveAction(player)
{
}

Inertie::~Inertie()
{
}

bool				Inertie::request()
{
  static const Distance		maxSpeed = 3;
  if (player.x)
  player.slowDown();
  return (false);
}
