//
// Gravity.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:07:50 2013 Brunier Jean
// Last update Tue Apr 16 21:23:01 2013 Brunier Jean
//

#include "Gravity.hh"

Gravity::Gravity(Player &player) : PassiveAction(player)
{
}

bool		Gravity::request()
{
  if (_player.sy() < 5)
    _player.sy(_player.sy() + 0.07);
  return (false);
}

int		Gravity::id()
{
  return (IAction::GRAVITY);
}
