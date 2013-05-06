//
// ActionFactory.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 10:37:50 2013 Brunier Jean
// Last update Sun May 05 21:49:09 2013 Brunier Jean
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
#include "Spin.hh"
#include "Death.hh"
#include "Tech.hh"
#include "Shield.hh"
#include "UpPunch.hh"
#include "Tempo.hh"
#include "HitCeiling.hh"
#include "HitLagg.hh"
#include "ThrowBall.hh"
#include "ThrowShuriken.hh"
#include "Curve.hh"
#include "AutoGun.hh"
#include "GunJump.hh"
#include "HorTP.hh"
#include "Television.hh"
#include "EffectiveTV.hh"

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
  if (action == IAction::DEATH)
    return (new Death(p));
  if (action == IAction::SPIN)
    return (new Spin(p));
  if (action == IAction::TECH)
    return (new Tech(p));
  if (action == IAction::SHIELD)
    return (new Shield(p));
  if (action == IAction::UP_PUNCH)
    return (new UpPunch(p));
  if (action == IAction::TEMPO)
    return (new Tempo(p));
  if (action == IAction::HIT_CEILING)
    return (new HitCeiling(p));
  if (action == IAction::HIT_LAGG)
    return (new HitLagg(p));
  if (action == IAction::THROW_BALL)
    return (new ThrowBall(p));
  if (action == IAction::THROW_SHURIKEN)
    return (new ThrowShuriken(p));
  if (action == IAction::CURVE)
    return (new Curve(p));
  if (action == IAction::AUTO_GUN)
    return (new AutoGun(p));
  if (action == IAction::GUN_JUMP)
    return (new GunJump(p));
  if (action == IAction::HOR_TP)
    return (new HorTP(p));
  if (action == IAction::EFFECTIVE_TV)
    return (new EffectiveTV(p));
  if (action == IAction::TELEVISION)
    return (new Television(p));
  throw(Exception("Action not exisiting."));
}
