//
// UpPunch.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 19:47:34 2013 Brunier Jean
// Last update Sat Apr 20 22:20:17 2013 Brunier Jean
//

#include "UpPunch.hh"

UpPunch::UpPunch(Player &player) :
	AAction(player, UP_PUNCH, new Hit(80, Position(-2, 3), player))
{
  _hit->add(20, Position(), _bones[Bones::HAND1]);
}

void	UpPunch::init(int)
{
  _hit->reset();
  _count = 60;
  _player = Position();
  _open = 160;
}

bool	UpPunch::allow(int)
{
  return (false);
}

IAction		*UpPunch::step()
{
  /*
  if (_player(Event::CEILING))
    {
      _player[IAction::DOUBLE_JUMP]->set(0);
      _count = 0;
    }
    */

  if (_count == 50)
    {
      _player.sy(-3);
      if (_player.orient() > 0)
	_player.sx(1);
      else
	_player.sx(-1);
    }
  if (_count-- == 0)
    {
      _player.sy(-1);
      return (_player[INERTIE]);
    }
    return (this);
}

bool		UpPunch::request()
{
  return ( _open == 0 && _player.key[Key::B] == 1 &&
	  _player.key[Key::VERT] == -1);
}

void		UpPunch::upBones()
{
  _bones.angle[Bones::FOOT1] = Angle(-20, 0);
  _bones.angle[Bones::FOOT2] = Angle(-40, 0);
  _bones.angle[Bones::KNEE1] = Angle(10, 0);
  _bones.angle[Bones::KNEE2] = Angle(-10, 0);

  _bones.angle[Bones::HAND1] = Angle(45, 0);
  _bones.angle[Bones::HAND2] = Angle(-20, 0);
  _bones.angle[Bones::ELBOW1] = Angle(130, 0);
  _bones.angle[Bones::ELBOW2] = Angle(-30, 0);

  _bones.angle[Bones::HEAD] = Angle(60, 0);
  _bones.angle[Bones::BODY] = Angle(MTIME * 0, 0);
}

void		UpPunch::check()
{
  if (_open)
    _open--;
}

void		UpPunch::print(Graphics &g) const
{
  static const int	size = 50;
  static const int	color[] =
    {
      0xFF0000,
      0xFF4400,
      0xFFFF00,
      0xFF9900
    };
  if (isActive() && _count <= 50)
    {
      for (int i = 0; i < 35; i++)
	g.line(_bones[Bones::HAND1] + Position(-30, 0) + MRAND_POS(20),
	    _bones[Bones::HAND1] + Position (20, 0) +
	    MRAND_POS(size), color[rand() % 4]);
    }
  else if (_open == 0)
    {
      for (int i = 0; i < 7; i++)
	g.circle(_bones[Bones::HAND1], (MTIME / 5 + i) % 12 + 5, color[(i) % 4]);
    }
}
