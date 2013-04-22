//
// DownDash.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 20:38:01 2013 Brunier Jean
// Last update Mon Apr 22 01:49:29 2013 Brunier Jean
//

#include "DownDash.hh"

DownDash::DownDash(Player &player) :
	AAction(player, DOWN_DASH, new Hit(60, Position(3, 3), player.orient()))
{
  _hit->add(20, Position(), _player.bones()[Bones::FOOT1]);
  _hit->add(20, Position(), _player.bones()[Bones::FOOT2]);
}

void	DownDash::init(int)
{
  _hit->reset();
  _count = 40;
}

bool	DownDash::allow(int a)
{
  return (PLANE_DEBUG || UP_PUNCH == a);
}

IAction		*DownDash::step()
{
  if (--_count == 0)
    {
  //    _player = Position(0, _player.orient() * 0);
      //_player[IAction::DOUBLE_JUMP]->set();
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
  if (PLANE_DEBUG)
    return (_player.key[Key::VERT] == 1);
  return (_player.key[Key::B] == 1 && _player.key[Key::VERT] == 1);
}

void		DownDash::upBones()
{
  _bones.angle[Bones::FOOT1] = Angle(10, 0);
  _bones.angle[Bones::FOOT2] = Angle(-5, 0);
  _bones.angle[Bones::KNEE1] = Angle(10, 0);
  _bones.angle[Bones::KNEE2] = Angle(5, 0);

  _bones.angle[Bones::HAND1] = Angle(-70, 0);
  _bones.angle[Bones::HAND2] = Angle(60, 0);
  _bones.angle[Bones::ELBOW1] = Angle(80, 0);
  _bones.angle[Bones::ELBOW2] = Angle(-100, 0);

  _bones.angle[Bones::HEAD] = Angle(0, 0);
  _bones.angle[Bones::BODY] = Angle(30, 0);
}
