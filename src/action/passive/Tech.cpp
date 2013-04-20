//
// Tech.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:55:33 2013 Brunier Jean
// Last update Sat Apr 20 01:04:29 2013 Brunier Jean
//

#include "Tech.hh"
#include "Player.hh"

Tech::Tech(Player &player) : PassiveAction(player, IAction::TECH)
{
}

void		Tech::check()
{
  if (_count > 0)
    _count--;
  else if (_player.key[Key::L])
    _count = 80;
}

int		Tech::val()
{
  return (_count >= 40);
}
