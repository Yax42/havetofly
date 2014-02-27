//
// ActionFactory.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 13 10:37:50 2013 Brunier Jean
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
#include "Dummy.hh"

#define SetAction(iaction, actionClass)		\
{											\
	if (action == IAction::iaction)			\
		return (new actionClass(p));		\
}\

IAction		*ActionFactory::get(int action, Player &p)
{
	SetAction(MOVE, Move);
	SetAction(INERTIE, Inertie);
	SetAction(GRAVITY, Gravity);
	SetAction(DOUBLE_JUMP,  DoubleJump);
	SetAction(HIT_WALL, HitWall);
	SetAction(STICK_CEILING, StickCeiling);
	SetAction(STICK_WALL, StickWall);
	SetAction(WALL_JUMP, WallJump);
	SetAction(STUN, Stun);
	SetAction(TECH, Tech);
	SetAction(TEMPO, Tempo);
	SetAction(HIT_LAGG, HitLagg);
	SetAction(DEATH, Death);
	SetAction(HIT_CEILING, HitCeiling);
	SetAction(HOR_DASH, HorDash);
	SetAction(THROW_SHURIKEN, ThrowShuriken);

	return (new DummyAction(p));
		//
	SetAction(DOWN_DASH, DownDash);
	SetAction(SPIN, Spin);
	SetAction(SHIELD, Shield);
	SetAction(UP_PUNCH, UpPunch);
	SetAction(THROW_BALL, ThrowBall);
	SetAction(CURVE, Curve);
	SetAction(AUTO_GUN, AutoGun);
	SetAction(GUN_JUMP, GunJump);
	SetAction(HOR_TP, HorTP);
	SetAction(EFFECTIVE_TV, EffectiveTV);
	SetAction(TELEVISION, Television);
	throw(Exception("Action not exisiting."));
}
