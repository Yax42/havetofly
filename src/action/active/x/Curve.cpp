//
// Curve.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 25 23:49:10 2013 Brunier Jean
// Last update Mon May 06 22:33:01 2013 Brunier Jean
//

#include "Curve.hh"

Curve::Curve(Player &player) : AAction(player, CURVE, new Hit(60, Position(-5, 1), player.orient(), 0, false, Hit::WALL))
{
  //_hit->add(35, Position(-5, 0), _bones[Bones::BODY]);
  //_hit->add(25, Position(), _bones[Bones::HEAD]);
}

void	Curve::init(int)
{
  _player = Position(-10, 0);
  _open = 0;
  _count = 38;
  _player[UP_PUNCH]->set();
}

bool	Curve::allow(int a)
{
  return (a > MOVE && _count < 13);
}

IAction		*Curve::step()
{
  if ((_player(Event::LEFT_WALL) && _player.orient() == -1) ||
      (_player(Event::RIGHT_WALL) && _player.orient() == 1))
    {
      _player = Position();
      return (_player[INERTIE]);
    }
  else if (_player(Event::RIGHT_WALL))
    _player.orient(-1);
  if (_count < 35 && _count > 5)
  _player = _player.speed() * Angle(_player.orient() * 6, 0);
  if (_count--)
    return (this);
  _player.sy(2);
  return (_player[INERTIE]);
}

bool		Curve::request()
{
  return (_player[UP_PUNCH]->val() && _player.key[Key::X] == 1 &&
	  _player.key(Key::R) && _player.key[Key::VERT] == -1);
}

void		Curve::upBones()
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
  if (_count > 35)
    _bones.angle[Bones::BODY] = Angle(0, 0);
  else if (_count > 5)
    _bones.angle[Bones::BODY] = Angle(-150 + (_count - 5) * 5, 0);
  else
    _bones.angle[Bones::BODY] = Angle(-150, 0);
}

void		Curve::check()
{
  if (_open)
    _open--;
}

void		Curve::set(int v)
{
  _open = !v;
}

int		Curve::val()
{
  return (_open);
}

void		Curve::print(Graphics &g) const
{
  static const int	color[] =
    {
      0xFF0000,
      0xFF4400,
      0xFFFF00,
      0xFF9900
    };

  if (isActive())
    {

      for (int i = 0; i < 100; i++)
	g.line(_bones[Bones::HEAD] + MRAND_POS_CI(24),
	    _bones[Bones::BODY] + MRAND_POS_CI(40),
	    color[rand() % 4]);
    }
}
