//
// UpPunch.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 19:47:34 2013 Brunier Jean
// Last update Tue Apr 23 18:37:29 2013 Brunier Jean
//

#include "UpPunch.hh"

UpPunch::UpPunch(Player &player) :
	AAction(player, UP_PUNCH, new Hit(130, Position(-2, 3), player.orient(), 30, false, Hit::ORIENT))
{
  _hit->add(20, Position(), _bones[Bones::HAND1]);
}

void	UpPunch::init(int v)
{
  if (v == 0 && !PLANE_DEBUG)
    {
      _player.setAction(TEMPO, id());
      _player[TEMPO]->set(10);
    }
  else
    {
      _hit->reset();
      _count = 50;
      _player.sy(-3);
      _player.sx(_player.orient());
      _open = 160;
    }
}

bool	UpPunch::allow(int)
{
  return (PLANE_DEBUG);
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

  if (_count-- == 0)
    {
      _player.sy(-1);
      return (_player[INERTIE]);
    }
    return (this);
}

bool		UpPunch::request()
{
  if (PLANE_DEBUG)
    return (_player.key[Key::VERT] == -1);
  return (_open == 0 && _player.key[Key::B] == 1 &&
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
  static const int	size = 25;
  static const int	color[] =
    {
      0xFF0000,
      0xFF4400,
      0xFFFF00,
      0xFF9900
    };
  if (isActive())
    {
      //g.line(Position(Distance(313539, 0), Distance(308258, 0)), Position(Distance(326746, 0), Distance(292605, 0)), 0);
      /*
      for (int i = 0; i < 350; i++)
	g.line(_bones[Bones::HAND1] + MRAND_POS(20) - Position(30, 0), _bones[Bones::HAND1] + MRAND_POS(size), 0);
      */
      for (int i = 0; i < 70; i++)
	g.line(_bones[Bones::HAND1] + Position(-30, 0) + MRAND_POS_CI(10),
	    _bones[Bones::HAND1] + Position (20, 0) +
	    MRAND_POS_CI(size), color[rand() % 4]);
    }
  else if (_open == 0)
    {
      /*
      for (int i = 0; i < 50; i++)
	g.line(_bones[Bones::HAND1], _bones[Bones::HAND1] + MRAND_POS_CI(8), color[rand() % 4]);
      g.circleLaid(_bones[Bones::HAND1], 8, color[0], color[2]);
      //g.circleLaid(_bones[Bones::HAND1], 6, color[0], color[2]);
      g.circleLaid(_bones[Bones::HAND1], 2, color[0], color[2]);
      g.circlePart(_bones[Bones::HAND1], 4, Angle(MTIME * 4 - 15, 0), Angle(110, 0), color[0]);
      g.circlePart(_bones[Bones::HAND1], 5, Angle(MTIME * 4, 0), Angle(110, 0), color[3]);
      g.circlePart(_bones[Bones::HAND1], 6, Angle(MTIME * 4 + 15, 0), Angle(110, 0), color[0]);
      */
//      g.circleLaid(_bones[Bones::HAND1], 5, color[0], color[2]);
      /*
      */
      for (int i = 0; i < 7; i++)
	g.circle(_bones[Bones::HAND1], (MTIME / 5 + i) % 12 + 1, color[(i) % 4]);
    }
}
