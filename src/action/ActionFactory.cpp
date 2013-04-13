//
// ActionFactory.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 10:37:50 2013 Brunier Jean
// Last update Sat Apr 13 10:45:17 2013 Brunier Jean
//

#include "Gravity.hh"
#include "Move.hh"
#include "DoubleJump.hh"
#include "Player.hh"

IAction		*ActionFactory::get(int action, Player &p)
{
  if (action == IAction::GRAVITY)
    return (new Gravity(p));
  else if (action == IAction::MOVE)
    return (new Move(p));
  else if (action == IAction::DOUBLE_JUMP)
    return (new DoubleJump(p));
  else
    return (NULL);
}
