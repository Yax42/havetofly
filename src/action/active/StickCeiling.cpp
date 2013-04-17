//
// StickCeiling.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 16 20:10:47 2013 Brunier Jean
// Last update Wed Apr 17 20:57:05 2013 Brunier Jean
//

#include "StickCeiling.hh"

StickCeiling::StickCeiling(Player &player) : AAction(player, NULL)
{
}

void	StickCeiling::init(int)
{
  _player = Position();
}

IAction		*StickCeiling::step()
{
  if (_player.key(Key::HOR) < 0)
    _player.orient(-1);
  else if (_player.key(Key::HOR) > 0)
    _player.orient(1);
  if (_player.key(Key::VERT) < 0)
    return (this);
  return (_player[IAction::INERTIE]);
}

bool		StickCeiling::request()
{
  return (_player(Event::CEILING) && _player.key(Key::VERT) < 0);
}

int		StickCeiling::id()
{
  return (IAction::STICK_CEILING);
}

void		StickCeiling::upBones()
{
  Bones		&bones = _player.bones();

  bones.angle[Bones::FOOT1] = Angle(90, 0);
  bones.angle[Bones::FOOT2] = Angle(90, 0);
  bones.angle[Bones::KNEE1] = Angle(-80, 0);
  bones.angle[Bones::KNEE2] = Angle(-90, 0);

  bones.angle[Bones::HAND1] = Angle(-70, 0);
  bones.angle[Bones::HAND2] = Angle(-60, 0);
  bones.angle[Bones::ELBOW1] = Angle(-80, 0);
  bones.angle[Bones::ELBOW2] = Angle(-100, 0);

  bones.angle[Bones::HEAD] = Angle(0, 0);
  bones.angle[Bones::BODY] = Angle(-90, 0);
}
