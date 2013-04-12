//
// Gravity.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:07:50 2013 Brunier Jean
// Last update Fri Apr 12 12:16:29 2013 Brunier Jean
//

#include "Gravity.hh"
#include "Player.hh"

Gravity(const Player &player) : PassiveAction(player)
{
}

Gravity::~Gravity()
{
}

bool		Gravity::request()
{
  player++;
  return (false);
}
