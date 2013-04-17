//
// DownDash.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 20:38:01 2013 Brunier Jean
// Last update Wed Apr 17 22:13:47 2013 Brunier Jean
//

#include "DownDash.hh"

DownDash::DownDash(Player &player) : AAction(player, NULL)
{
}

void	DownDash::init(int)
{
  _count = 50;
}

bool	DownDash::allow(int)
{
  return (false);
}

IAction		*DownDash::step()
{
  if (--_count == 0)
    {
      _player[IAction::DOUBLE_JUMP]->reset();
      _player = Position(3, _player.orient() * 4);
      return (_player[IAction::INERTIE]);
    }
  if (_player(Event::WALL))
    _player.orient(-_player.orient());
  _player = Position(4, _player.orient() * 4);
  return (this);
}

bool		DownDash::request()
{
  return (_player.key(Key::VERT) > 0 && _player.key(Key::B));
}

int		DownDash::id()
{
  return (IAction::DOWN_DASH);
}

void		DownDash::upBones()
{
  Bones		&bones = _player.bones();

  bones.angle[Bones::FOOT1] = Angle(10, 0);
  bones.angle[Bones::FOOT2] = Angle(-5, 0);
  bones.angle[Bones::KNEE1] = Angle(10, 0);
  bones.angle[Bones::KNEE2] = Angle(5, 0);

  bones.angle[Bones::HAND1] = Angle(-70, 0);
  bones.angle[Bones::HAND2] = Angle(-60, 0);
  bones.angle[Bones::ELBOW1] = Angle(80, 0);
  bones.angle[Bones::ELBOW2] = Angle(-100, 0);

  bones.angle[Bones::HEAD] = Angle(0, 0);
  bones.angle[Bones::BODY] = Angle(45, 0);
}
