//
// StickWall.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 16 21:05:53 2013 Brunier Jean
// Last update Tue Apr 16 22:00:21 2013 Brunier Jean
//

#include "StickWall.hh"

StickWall::StickWall(Player &player) : AAction(player, NULL)
{
}

bool	StickWall::allow(int a)
{
  return (a == IAction::WALL_JUMP);
}
void	StickWall::init(int)
{
}

IAction		*StickWall::step()
{
  if (_player.sy() < 5)
    _player.sy(_player.sy() + 0.01);
  if (_player.sy() < 0)
    _player.sy(_player.sy() + 0.1);
  if (_player(Event::LEFT_WALL) && *_player.key(Key::HOR) < 0)
    return (this);
  if (_player(Event::RIGHT_WALL) && *_player.key(Key::HOR) > 0)
    return (this);
  return (_player[IAction::INERTIE]);
}

bool		StickWall::request()
{
  if (_player(Event::LEFT_WALL) && *_player.key(Key::HOR) < 0)
    return (true);
  if (_player(Event::RIGHT_WALL) && *_player.key(Key::HOR) > 0)
    return (true);
  return (false);
}

int		StickWall::id()
{
  return (IAction::STICK_WALL);
}

void		StickWall::upBones()
{
  Bones		&bones = _player.bones();

  bones.angle[Bones::FOOT1] = Angle(-90, 0);
  bones.angle[Bones::FOOT2] = Angle(-90, 0);
  bones.angle[Bones::KNEE1] = Angle(80, 0);
  bones.angle[Bones::KNEE2] = Angle(90, 0);

  bones.angle[Bones::HAND1] = Angle(70, 0);
  bones.angle[Bones::HAND2] = Angle(60, 0);
  bones.angle[Bones::ELBOW1] = Angle(80, 0);
  bones.angle[Bones::ELBOW2] = Angle(100, 0);

  bones.angle[Bones::HEAD] = Angle(0, 0);
  bones.angle[Bones::BODY] = Angle(0, 0);
}
