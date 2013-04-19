//
// Stun.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 23:22:36 2013 Brunier Jean
// Last update Fri Apr 19 19:28:53 2013 Brunier Jean
//

#include "Stun.hh"

Stun::Stun(Player &player) : AAction(player, STUN, NULL)
{
}

void	Stun::set(int val)
{
  _count = val;
}

void	Stun::init(int v)
{
  _count = v;
}

bool	Stun::allow(int a)
{
  return (a < MOVE);
}

IAction		*Stun::step()
{
  if (_count--)
    return (this);
  return (_player[IAction::INERTIE]);
}

bool		Stun::request()
{
  return (false);
}

void		Stun::upBones()
{
  Bones		&bones = _player.bones();

  bones.angle[Bones::FOOT1] = Angle(0, 0);
  bones.angle[Bones::FOOT2] = Angle(0, 0);
  bones.angle[Bones::KNEE1] = Angle(MGRAD_CAP(MTIME * 9, 30, 60), 0);
  bones.angle[Bones::KNEE2] = Angle(MGRAD_CAP(MTIME * 9 + 180, -90, 60), 0);

  bones.angle[Bones::HAND1] = Angle(0, 0);
  bones.angle[Bones::HAND2] = Angle(0, 0);
  bones.angle[Bones::ELBOW1] = Angle(MGRAD_CAP(MTIME * 10, 60, 60), 0);
  bones.angle[Bones::ELBOW2] = Angle(MGRAD_CAP(MTIME * 10 + 180, -120, 60), 0);

  bones.angle[Bones::HEAD] = Angle(0, 0);
  bones.angle[Bones::BODY] = Angle(MTIME * 0 + 180, 0);
}
