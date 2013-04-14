/*
** Position.cpp for src in /home/brunie_j/local/nibbler/nibbler/src
**
** Made by Brunier Jean
** Login   <brunie_j@epitech.net>
**
** Started on  Tue Mar 05 17:12:19 2013 Brunier Jean
** Last update Sun Mar 17 12:18:44 2013 Brunier Jean
*/

#include "Position.hh"
#include "Math.hh"

/****************/
/* CONSTRUCTORS */
/****************/

Position::~Position(){}

Position::Position()
{
}

Position::Position(const Distance &y, const Distance &x) : _y(y), _x(x)
{
}


Position::Position(Angle const &angle, const Distance &distance)
{
  _x = distance * Math::cos(angle);
  _y = distance * Math::sin(angle);
}

Position::Position(Position const &other) : _y(other._y), _x(other._x)
{
}

Position	&Position::operator=(Position const &other)
{
  _y = other._y;
  _x = other._x;
  return (*this);
}

/****************/
/* COMPARAISONS */
/****************/

bool		Position::operator==(Position const &other) const
{
  return (_x.intVal() == other._x.intVal() && _y.intVal() == other._y.intVal());
}

bool		Position::operator!=(Position const &other) const
{
  return (!operator==(other));
}

/***********************/
/* POSITION OPERATIONS */
/***********************/

Position	&Position::operator+=(Position const &other)
{
  _y += other._y;
  _x += other._x;
  return (*this);
}

Position	&Position::operator-=(Position const &other)
{
  _y -= other._y;
  _x -= other._x;
  return (*this);
}

Position	Position::operator+(Position const &other) const
{
  return (Position(_y + other._y, _x + other._x));
}

Position	Position::operator-(Position const &other) const
{
  return (Position(_y - other._y, _x - other._x));
}

Position	&Position::operator*=(Position const &other)
{
  _y *= other._y;
  _x *= other._x;
  return (*this);
}

Position	&Position::operator/=(Position const &other)
{
  _y /= other._y;
  _x /= other._x;
  return (*this);
}

Position	Position::operator*(Position const &other) const
{
  return (Position(_y * other._y, _x * other._x));
}

Position	Position::operator/(Position const &other) const
{
  return (Position(_y / other._y, _x / other._x));
}

/***********************/
/* DISTANCE OPERATIONS */
/***********************/
Position	Position::operator+(const Distance &v) const
{
  return (Position(_y + v, _x + v));
}

Position	Position::operator-(const Distance &v) const
{
  return (Position(_y - v, _x - v));
}

Position	Position::operator*(const Distance &v) const
{
  return (Position(_y * v, _x * v));
}

Position	Position::operator/(const Distance &v) const
{
  return (Position(_y / v, _x / v));
}

Position	&Position::operator+=(const Distance &v)
{
  _x += v;
  _y += v;
  return (*this);
}

Position	&Position::operator-=(const Distance &v)
{

  _x -= v;
  _y -= v;
  return (*this);
}

Position	&Position::operator*=(const Distance &v)
{
  _x *= v;
  _y *= v;
  return (*this);
}

Position	&Position::operator/=(const Distance &v)
{

  _x /= v;
  _y /= v;
  return (*this);
}

/************/
/* ROTATION */
/************/

Position		Position::operator*(const Angle& a) const
{
  return (Position(a + angle(), distance()));
}

Position		&Position::operator*=(const Angle& angle)
{
  Distance		d = distance();
  Angle			a(angle + this->angle());

  _x = (d * Math::cos(a.rad()));
  _y = (d * Math::sin(a.rad()));
  return (*this);
}

Position		&Position::rotate(const Angle &a, Position const &center)
{
  Position	origin(*this - center);
  Position	next(Position(origin.angle() + a, origin.distance()) + center);

  _x = next._x;
  _y = next._y;
  return (*this);
}

/***********/
/* GETTERS */
/***********/

int			Position::x() const
{
  return (_x.intVal());
}

int			Position::y() const
{
  return (_y.intVal());
}

void			Position::x(Distance const &x)
{
  _x = x;
}

void			Position::y(Distance const &y)
{
  _y = y;
}

const Distance		&Position::xDist() const
{
  return (_x);
}

const Distance		&Position::yDist() const
{
  return (_y);
}

Distance		&Position::xDist()
{
  return (_x);
}

Distance		&Position::yDist()
{
  return (_y);
}

Distance	Position::distance() const
{
  return (Distance(Math::sqrt(_x * _x + _y * _y)));
}

Angle		Position::angle() const
{
  if (_x.longVal() == 0 && _y.longVal() == 0)
    return (Angle());
  return (Angle(Math::acos((_x / distance()).longVal()) * (_y.longVal() < 0 ? -1 : 1)));
}

std::ostream	&operator<<(std::ostream &s, Position const &pos)
{
  s << "[" << pos.y() << ", " << pos.x() << "]";
  return (s);
}
