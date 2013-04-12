//
// PassiveAction.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 11:40:32 2013 Brunier Jean
// Last update Fri Apr 12 11:43:16 2013 Brunier Jean
//

#include "PassiveAction.hh"

PassiveAction(const Player &player) : AAction(player, NULL)
{
}

PassiveAction::~Gravity()
{
}

int	PassiveAction::init()
{
  return (0);
}

bool	PassiveAction::allow(int a)
{
  return (true);
}

IAction		*PassiveAction::step()
{
  return (NULL);
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
