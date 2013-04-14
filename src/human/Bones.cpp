//
// Bones.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 17:23:55 2013 Brunier Jean
// Last update Sun Apr 14 17:12:29 2013 Brunier Jean
//

#include "Bones.hh"
#include "Graphics.hh"
#include "Circle.hh"

#define U_ARM		100
#define L_ARM		100
#define ARM		(U_ARM + L_ARM)

#define U_LEGG		100
#define L_LEGG		100
#define LEGG  		(U_LEGG + L_LEGG)

#define U_BACK		100
#define L_BACK		100
#define BACK		(U_BACK + L_BACK)

#define HEAD		50

Bones::Bones(const Position &centre, int color, int color2, const int &orient) :
	_center(centre), _orient(orient), _color(color), _color2(color2)
{
}

Bones::~Bones()
{
}

void		Bones::print(Graphics &g) const
{
  Position	sex = Position(_angle, _back);

  g.circle(_center + Position(_angle, HEAD), HEAD, _color);
  g.bend(_center, U_BACK, sex, L_BACK, _color);
  g.bend(_center, U_ARM, _hand1, L_ARM, _color);
  g.bend(_center, U_ARM, _hand2, L_ARM, _color);
  g.bend(_center, U_LEGG, _foot1, L_LEGG, _color);
  g.bend(_center, U_LEGG, _foot2, L_LEGG, _color);
}

void	Bones::up(Position const &old, Position &next, int max)
{
  next = old * _angle;
  if (next.distance() > max)
    next = Position(next.angle(), max);
}

void	Bones::check()
{
  _angle = (Position(angle, 1) * Position(1, _orient)).angle();
  up(foot1, _foot1, LEGG);
  up(foot2, _foot2, LEGG);
  up(hand1, _hand1, LEGG);
  up(hand2, _hand2, LEGG);
  _back = back;
  if (_back > BACK)
    _back = BACK;
  _head = head;
  if (_head.deg() > 90)
    _head = Angle(90, 0);
  else if (_head.deg() < -90)
    _head = Angle(-90, 0);
}
  //void	circle(Position const &pos, const Distance &size, int color);
