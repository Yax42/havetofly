//
// RatioPosition.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 22 23:16:52 2013 Brunier Jean
// Last update Tue Apr 23 01:49:41 2013 Brunier Jean
//

#include "RatioPosition.hh"
#include "Math.hh"

/****************/
/* CONSTRUCTORS */
/****************/

RatioPosition::~RatioPosition(){}

RatioPosition::RatioPosition()
{
}

RatioPosition::RatioPosition(const Position &pos) :
   _y(MFLOAT_TO_RATIO(pos.yDist().longVal()), 0), _x(MFLOAT_TO_RATIO(pos.xDist().longVal()), 0)
{
}

RatioPosition::RatioPosition(const Ratio &y, const Ratio &x) : _y(y), _x(x)
{
}

RatioPosition::RatioPosition(const Ratio &y, const Ratio &x, int) :
 	 _y(y.longVal(), 0), _x(x.longVal(), 0)
{
}

RatioPosition::RatioPosition(Angle const &angle, const Distance &distance)
{
  _y = Math::sin(angle) * distance;
  _x = Math::cos(angle) * distance;
}

RatioPosition::RatioPosition(RatioPosition const &other) : _y(other._y), _x(other._x)
{
}

RatioPosition	&RatioPosition::operator=(RatioPosition const &other)
{
  _y = other._y;
  _x = other._x;
  return (*this);
}

/****************/
/* COMPARAISONS */
/****************/

bool		RatioPosition::operator==(RatioPosition const &other) const
{
  return (_x.longVal() == other._x.longVal() && _y.longVal() == other._y.longVal());
}

bool		RatioPosition::operator!=(RatioPosition const &other) const
{
  return (!operator==(other));
}

/***********************/
/* POSITION OPERATIONS */
/***********************/

RatioPosition	&RatioPosition::operator+=(RatioPosition const &other)
{
  _y += other._y;
  _x += other._x;
  return (*this);
}

RatioPosition	&RatioPosition::operator-=(RatioPosition const &other)
{
  _y -= other._y;
  _x -= other._x;
  return (*this);
}

RatioPosition	RatioPosition::operator+(RatioPosition const &other) const
{
  return (RatioPosition(_y + other._y, _x + other._x));
}

RatioPosition	RatioPosition::operator-(RatioPosition const &other) const
{
  return (RatioPosition(_y - other._y, _x - other._x, 0));
}

/***********************/
/* DISTANCE OPERATIONS */
/***********************/
RatioPosition	RatioPosition::operator+(const Ratio &v) const
{
  return (RatioPosition(_y + v, _x + v));
}

RatioPosition	RatioPosition::operator-(const Ratio &v) const
{
  return (RatioPosition(_y - v, _x - v));
}


RatioPosition	&RatioPosition::operator+=(const Ratio &v)
{
  _x += v;
  _y += v;
  return (*this);
}

RatioPosition	&RatioPosition::operator-=(const Ratio &v)
{

  _x -= v;
  _y -= v;
  return (*this);
}

/////
RatioPosition	RatioPosition::operator*(const Distance &v) const
{
  return (RatioPosition(_y * v, _x * v));
}

RatioPosition	RatioPosition::operator/(const Distance &v) const
{
  RatioPosition	tmp(_y, _x);

  tmp._y /= v;
  tmp._x /= v;
  return (tmp);
}

RatioPosition	&RatioPosition::operator*=(const Distance &v)
{
  _x *= v;
  _y *= v;
  return (*this);
}

RatioPosition	&RatioPosition::operator/=(const Distance &v)
{

  _x /= v;
  _y /= v;
  return (*this);
}

/************/
/* ROTATION */
/************/

RatioPosition		RatioPosition::operator*(const Angle& a) const
{
  return (RatioPosition(a + angle(), distance()));
}

RatioPosition		&RatioPosition::operator*=(const Angle& angle)
{
  Distance		d = distance();
  Angle			a(angle + this->angle());

  _x = (Math::cos(a.rad()) * d);
  _y = (Math::sin(a.rad()) * d);
  return (*this);
}

RatioPosition		&RatioPosition::rotate(const Angle &a, RatioPosition const &center)
{
  RatioPosition	origin(*this - center);
  RatioPosition	next(RatioPosition(origin.angle() + a, origin.distance()) + center);

  _x = next._x;
  _y = next._y;
  return (*this);
}

/***********/
/* GETTERS */
/***********/

int			RatioPosition::x() const
{
  return (_x.floatVal());
}

int			RatioPosition::y() const
{
  return (_y.floatVal());
}

RatioPosition		&RatioPosition::x(Ratio const &x)
{
  _x = x;
  return (*this);
}

RatioPosition		&RatioPosition::y(Ratio const &y)
{
  _y = y;
  return (*this);
}

const Ratio	&RatioPosition::xRatio() const
{
  return (_x);
}

const Ratio	&RatioPosition::yRatio() const
{
  return (_y);
}

Distance	RatioPosition::xDist() const
{
  return (_x);
}

Distance	RatioPosition::yDist() const
{
  return (_y);
}

Distance	RatioPosition::distance() const
{
  return (Math::sqrt(_x * _x + _y * _y));
}

Angle		RatioPosition::angle() const
{
  if (distance() == 0)
    return (Angle());
  return (Angle(Math::acos(_x / distance()) * (_y.longVal() < 0 ? -1 : 1)));
}

std::ostream	&operator<<(std::ostream &s, RatioPosition const &pos)
{
  s << "[" << pos.yRatio() << ", " << pos.xRatio() << "]";
  return (s);
}

/*
RatioPosition::operator Position()
{
  std::cout << *this << std::endl;
  return (Position(Distance(_y), Distance(_x)));
}
*/
