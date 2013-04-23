//
// Gravity.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:07:50 2013 Brunier Jean
// Last update Tue Apr 23 15:22:14 2013 Brunier Jean
//

#include "Gravity.hh"

Gravity::Gravity(Player &player) : PassiveAction(player, GRAVITY)
{
}

bool		Gravity::request()
{
  static const Ratio	MIN_SPEED(8);

  if (_player.sy() < MIN_SPEED)
    _player.sy(_player.sy() + 0.035); //2
  return (false);
}
