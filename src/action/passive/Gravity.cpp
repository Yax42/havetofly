//
// Gravity.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:07:50 2013 Brunier Jean
// Last update Fri Apr 19 18:15:12 2013 Brunier Jean
//

#include "Gravity.hh"

Gravity::Gravity(Player &player) : PassiveAction(player, IAction::GRAVITY)
{
}

bool		Gravity::request()
{
  if (_player.sy() < 8)
    _player.sy(_player.sy() + 0.035); //2
  return (false);
}
