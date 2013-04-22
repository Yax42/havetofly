//
// HorDash.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 18 23:26:54 2013 Brunier Jean
// Last update Mon Apr 22 01:49:16 2013 Brunier Jean
//

#include "HorDash.hh"

HorDash::HorDash(Player &player) :
	AAction(player, HOR_DASH, new Hit(10, Position(8, 1), player.orient(), Hit::WALL))
{
  _hit->add(20, Position(), _player.bones()[Bones::HEAD]);
}

void	HorDash::init(int v)
{
  if (v == 0 && !PLANE_DEBUG)
    {
      _player.setAction(TEMPO, id());
      _player[TEMPO]->set(15);
    }
  else
    {
      _hit->reset();
      _count = 35;
      _player = Position(0, 6 * _player.orient());
      _open = 0;
    }
}

bool	HorDash::allow(int a)
{
  return (a == DOWN_DASH || PLANE_DEBUG);
}

IAction		*HorDash::step()
{
  if (_count-- == 0 ||
      (_player(Event::LEFT_WALL) && _player.orient() == -1) ||
      (_player(Event::RIGHT_WALL) && _player.orient() == 1))
    {
      _player.sx(_player.orient());
      return (_player[INERTIE]);
    }
  return (this);
}

bool		HorDash::request()
{
  if (PLANE_DEBUG)
    return (_player.key[Key::HOR]);
  return (_open && _player.key[Key::B] == 1 && _player.key[Key::HOR]);
}

void		HorDash::upBones()
{
  _bones.angle[Bones::FOOT1] = Angle(10, 0);
  _bones.angle[Bones::FOOT2] = Angle(-5, 0);
  _bones.angle[Bones::KNEE1] = Angle(10, 0);
  _bones.angle[Bones::KNEE2] = Angle(5, 0);

  _bones.angle[Bones::HAND1] = Angle(70, 0);
  _bones.angle[Bones::HAND2] = Angle(-60, 0);
  _bones.angle[Bones::ELBOW1] = Angle(-80, 0);
  _bones.angle[Bones::ELBOW2] = Angle(100, 0);

  _bones.angle[Bones::HEAD] = Angle(0, 0);
  _bones.angle[Bones::BODY] = Angle(-90, 0);
}

void		HorDash::check()
{
  if (_player(Event::WALL) && !isActive())
    _open = 1;
}

void		HorDash::print(Graphics &g) const
{
  if (_open)
    {
      g.sponge(_bones[Bones::HAND1], 4, 5, 2, Angle(MTIME * 10, 0), (rand() % 2) * 0xFFFFFF);
      g.sponge(_bones[Bones::HAND2], 4, 5, 2, Angle(MTIME * 10, 0), (rand() % 2) * 0xFFFFFF);
    }
  if (isActive())
    {
      for (int i = 0; i < 5; i++)
      {
	g.circle(_bones[Bones::FOOT1] + Position (rand() % 30 - 15,
	      rand() % 30 - 15), rand() % 10 + 5,  0xFF0000);
	g.circle(_bones[Bones::FOOT1] + Position (rand() % 30 - 15,
	      rand() % 30 - 15), rand() % 10 + 5,  0xFFFF00);
	g.circle(_bones[Bones::FOOT2] + Position (rand() % 30 - 15,
	      rand() % 30 - 15), rand() % 10 + 5,  0xFF4400);
	g.circle(_bones[Bones::FOOT1] + Position (rand() % 30 - 15,
	      rand() % 30 - 15), rand() % 10 + 5,  0xFF9900);
      }
    }
}
