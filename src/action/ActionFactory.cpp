//
// ActionFactory.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 10:37:50 2013 Brunier Jean
// Last update Sun Apr 14 19:00:41 2013 Brunier Jean
//

#include "ActionFactory.hh"
#include "Exception.hh"
#include "Player.hh"

#include "Move.hh"
#include "Inertie.hh"
#include "Gravity.hh"
#include "DoubleJump.hh"

IAction		*ActionFactory::get(int action, Player &p)
{
  if (action == IAction::MOVE)
    return (new Move(p));
  if (action == IAction::INERTIE)
    return (new Inertie(p));
  if (action == IAction::GRAVITY)
    return (new Gravity(p));
  else if (action == IAction::DOUBLE_JUMP)
    return (new DoubleJump(p));
  throw(Exception("Action not exisiting."));
}
