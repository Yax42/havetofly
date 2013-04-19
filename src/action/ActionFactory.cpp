//
// ActionFactory.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 10:37:50 2013 Brunier Jean
// Last update Thu Apr 18 23:27:39 2013 Brunier Jean
//

#include "ActionFactory.hh"
#include "Exception.hh"
#include "Player.hh"

#include "Move.hh"
#include "Inertie.hh"
#include "Gravity.hh"
#include "DoubleJump.hh"
#include "HitWall.hh"
#include "StickCeiling.hh"
#include "StickWall.hh"
#include "WallJump.hh"
#include "DownDash.hh"
#include "Stun.hh"
#include "HorDash.hh"

IAction		*ActionFactory::get(int action, Player &p)
{
  if (action == IAction::MOVE)
    return (new Move(p));
  if (action == IAction::INERTIE)
    return (new Inertie(p));
  if (action == IAction::GRAVITY)
    return (new Gravity(p));
  if (action == IAction::DOUBLE_JUMP)
    return (new DoubleJump(p));
  if (action == IAction::HIT_WALL)
    return (new HitWall(p));
  if (action == IAction::STICK_CEILING)
    return (new StickCeiling(p));
  if (action == IAction::STICK_WALL)
    return (new StickWall(p));
  if (action == IAction::WALL_JUMP)
    return (new WallJump(p));
  if (action == IAction::DOWN_DASH)
    return (new DownDash(p));
  if (action == IAction::STUN)
    return (new Stun(p));
  if (action == IAction::HOR_DASH)
    return (new HorDash(p));
  throw(Exception("Action not exisiting."));
}
