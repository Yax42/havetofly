//
// Tech.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:55:33 2013 Brunier Jean
// Last update Fri Apr 19 18:16:30 2013 Brunier Jean
//

#include "Tech.hh"
#include "Player.hh"

Tech(const Player &player) : PassiveAction(player, IAction::TECH)
{
}

Tech::~Tech()
{
}

void		Tech::check()
{
  if (_count > 0)
    _count--;
  else if (player[K_L])
    _count = 40;
}

int		Tech::val()
{
  int	tmp = _count;

  _count = 0;
  return (tmp >= 20);
}
