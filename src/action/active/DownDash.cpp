//
// DownDash.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 20:38:01 2013 Brunier Jean
// Last update Thu Apr 18 10:51:19 2013 Brunier Jean
//

#include "DownDash.hh"

DownDash::DownDash(Player &player) :
	AAction(player, new Hit(50, Position(3, 3), player))
{
  _hit->add(20, Position(40, 30));
}

void	DownDash::init(int)
{
  _hit->reset();
  _count = 40;
}

bool	DownDash::allow(int)
{
  return (false);
}

IAction		*DownDash::step()
{
  if (--_count == 0)
    {
      _player[IAction::DOUBLE_JUMP]->set();
  //    _player = Position(0, _player.orient() * 0);
      return (_player[IAction::INERTIE]);
    }
  if (_player(Event::WALL))
  {
    _player[IAction::WALL_JUMP]->init();
    return (_player[IAction::WALL_JUMP]);
  }

    /*
    _player.orient(-_player.orient());
  */
  _player = Position(5, _player.orient() * 4);
  return (this);
}

bool		DownDash::request()
{
  return (_player.key(Key::VERT) > 0 && _player.key[Key::B] == 1);
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
  bones.angle[Bones::BODY] = Angle(30, 0);
}
