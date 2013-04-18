//
// WallJump.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 16 21:44:12 2013 Brunier Jean
// Last update Thu Apr 18 09:59:59 2013 Brunier Jean
//

#include "WallJump.hh"

WallJump::WallJump(Player &player) : AAction(player, NULL)
{
}

void	WallJump::init(int)
{
  _count = 50;
  if (_player(Event::LEFT_WALL))
    _player = Position(-3.33, 2); //2/3
  else if (_player(Event::RIGHT_WALL))
    _player = Position(-3.333, -2); //2/3
  else
    throw(Exception("Wall jump without sticking the wall."));
}

bool	WallJump::allow(int a)
{
  return (a != IAction::MOVE && a != DOWN_DASH);
}

IAction		*WallJump::step()
{
  if (--_count == 0)
    return (_player[IAction::INERTIE]);
  return (this);
}

bool		WallJump::request()
{
  return (_player.key[Key::A] == 1 && _player.currentAction() == IAction::STICK_WALL);
}

int		WallJump::id()
{
  return (IAction::WALL_JUMP);
}

void		WallJump::upBones()
{
  Bones		&bones = _player.bones();

  bones.angle[Bones::FOOT1] = Angle(-125, 0);
  bones.angle[Bones::FOOT2] = Angle(-120, 0);
  bones.angle[Bones::KNEE1] = Angle(120, 0);
  bones.angle[Bones::KNEE2] = Angle(130, 0);

  bones.angle[Bones::HAND1] = Angle(130, 0);
  bones.angle[Bones::HAND2] = Angle(120, 0);
  bones.angle[Bones::ELBOW1] = Angle(20, 0);
  bones.angle[Bones::ELBOW2] = Angle(25, 0);

  bones.angle[Bones::HEAD] = Angle(-90, 0);
  bones.angle[Bones::BODY] = Angle(MTIME * 16, 0);
}
