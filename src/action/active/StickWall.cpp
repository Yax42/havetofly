//
// StickWall.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 16 21:05:53 2013 Brunier Jean
// Last update Fri Apr 19 19:28:38 2013 Brunier Jean
//

#include "StickWall.hh"

StickWall::StickWall(Player &player) : AAction(player, STICK_WALL, NULL)
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
  if (_player.sy() < 3.3) // 2/3
    _player.sy(_player.sy() + 0.00666); //2/3
  if (_player.sy() < 0)
    _player.sy(_player.sy() + 0.066); //2/3
  if (_player(Event::LEFT_WALL) && _player.key(Key::HOR) < 0)
    return (this);
  if (_player(Event::RIGHT_WALL) && _player.key(Key::HOR) > 0)
    return (this);
  return (_player[IAction::INERTIE]);
}

bool		StickWall::request()
{
  if (_player(Event::LEFT_WALL) && _player.key(Key::HOR) < 0)
    return (true);
  if (_player(Event::RIGHT_WALL) && _player.key(Key::HOR) > 0)
    return (true);
  return (false);
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
