//
// Bones.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 17:23:55 2013 Brunier Jean
// Last update Wed Apr 17 22:03:23 2013 Brunier Jean
//

#include "Bones.hh"
#include "Graphics.hh"
#include "Circle.hh"
#include "Math.hh"

#include <iostream>

const int	Bones::_size[Bones::COUNT] =
{
  20,	// FOOT1
  20,	// KNEE1
  20,	// HAND1
  14,	// ELBOW1
  20,	// FOOT2
  20,	// KNEE2
  20,	// HAND2
  14,	// ELBOW2
  16,	// HEAD
  22	// BODY
};

Bones::Bones(const Position &centre, int color, int color2, const int &orient) :
	_center(centre), _orient(orient), _color(color), _color2(color2)
{
}

Bones::~Bones()
{
}

void		Bones::print(Graphics &g)
{
  Position	center = _center;
  check();
  Position	pos[Bones::COUNT];

  pos[BODY] = center + Position(_angle[BODY], _size[BODY]);
  pos[HEAD] = center - Position(_angle[HEAD] + _angle[BODY], _size[HEAD]);
  for (int i = 0; i < 3; i++)
    g.circle(pos[HEAD], _size[HEAD] - i, _color);
  g.line(center, pos[BODY], _color, 6);
  for (int i = 0; i < 4; i++)
    {
      pos[i * 2 + 1] = ((i % 2) ? center : pos[BODY]) +
	Position(_angle[i * 2 + 1] +
	_angle[BODY], _size[i * 2 + 1]);
      pos[i * 2] = pos[i * 2 + 1] + Position(_angle[i * 2] +
	  _angle[BODY] + _angle[i * 2 + 1], _size[i * 2]);
       g.line(((i % 2) ? center : pos[BODY]), pos[i * 2 + 1], _color, 6);
       g.line(pos[i * 2 + 1], pos[i * 2], _color, 6);
    }


  /*
  g.bend(_center, U_ARM, _hand1, L_ARM, _color);
  g.bend(_center, U_ARM, _hand2, L_ARM, _color);
  g.bend(_center, U_LEGG, _foot1, L_LEGG, _color);
  g.bend(_center, U_LEGG, _foot2, L_LEGG, _color);
  */
}

void	Bones::up(Position const &, Position &, int)
{
  /*
  next = old * _angle;
  if (next.distance() > max)
    next = Position(next.angle(), max);
  */
}

void	Bones::check()
{
  for (int i = 0; i < Bones::COUNT; i++)
    _angle[i] = angle[i];

  /*
  if (_angle[HEAD].deg() > 90 && _angle[HEAD].deg() < 180)
    _angle[HEAD] = Angle(90, 0);
  else if (_angle[HEAD].deg() < 270 && _angle[HEAD].deg() >= 180)
    _angle[HEAD] = Angle(-90, 0);
    */
  if (_orient > 0)
    for (int i = 0; i < Bones::COUNT; i++)
      _angle[i] = _angle[i].mirrorX();
  _angle[BODY] += Angle(90, 0);

}
