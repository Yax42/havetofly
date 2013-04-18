//
// PassiveAction.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 11:40:32 2013 Brunier Jean
// Last update Wed Apr 17 23:21:59 2013 Brunier Jean
//

#include "PassiveAction.hh"

PassiveAction::PassiveAction(Player &player) : AAction(player, NULL)
{
}

bool	PassiveAction::allow(int)
{
  return (true);
}

IAction		*PassiveAction::step()
{
  return (_player[IAction::INERTIE]);
}

bool		PassiveAction::request()
{
  return (false);
}

void		PassiveAction::check()
{
}

int	PassiveAction::val()
{
  return (0);
}
void		PassiveAction::upBones()
{
}
