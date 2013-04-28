//
// DownDash.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 20:38:01 2013 Brunier Jean
// Last update Sun Apr 28 19:49:57 2013 Brunier Jean
//

#include "DownDash.hh"

DownDash::DownDash(Player &player) :
	AAction(player, DOWN_DASH, new Hit(60, Position(3, 3), player.orient(), 15, false, Hit::ORIENT))
{
  _hit->add(15, Position(), _bones[Bones::FOOT1]);
  _hit->add(15, Position(), _bones[Bones::FOOT2]);
}

void	DownDash::init(int v)
{
  if (v == 0 && !PLANE_DEBUG)
    {
      _player.setAction(TEMPO, id());
      _player[TEMPO]->set(10);
    }
  else
    {
      _player[AUTO_GUN]->set(4);
      _player = Position(5, _player.orient() * 4);
      _hit->reset();
      _count = 40;
    }
}

bool	DownDash::allow(int)
{
  return (PLANE_DEBUG);
}

IAction		*DownDash::step()
{
  if (--_count == 0)
    {
  //    _player = Position(0, _player.orient() * 0);
      //_player[IAction::DOUBLE_JUMP]->set();
      return (_player[IAction::INERTIE]);
    }
  if ((_player(Event::LEFT_WALL) && _player.orient() < 0) ||
      (_player(Event::RIGHT_WALL) && _player.orient() > 0))
  {
    _player[IAction::WALL_JUMP]->init();
    return (_player[IAction::WALL_JUMP]);
  }

    /*
    _player.orient(-_player.orient());
  */
  if (_player(Event::DID_HIT) && _count > 10)
    _count = 10;
  _player = Position(5, _player.orient() * 4);
  return (this);
}

bool		DownDash::request()
{
  if (PLANE_DEBUG)
    return (_player.key[Key::VERT] == 1);
  return (_player.key[Key::B] == 1 && !_player.key(Key::R) && _player.key[Key::VERT] == 1);
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
