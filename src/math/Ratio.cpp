//
// Ratio.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 15 14:02:52 2013 Brunier Jean
// Last update Tue Apr 23 00:33:56 2013 Brunier Jean
//

#include "Ratio.hh"
#include "Math.hh"
#include "Distance.hh"

Ratio::Ratio() : _val(0)
{
}

Ratio::Ratio(int v) : _val(MTO_RATIO(v))
{
}

Ratio::Ratio(long v) : _val(MTO_RATIO(v))
{
}

Ratio::Ratio(long v, int) : _val(v)
{
}

Ratio::Ratio(float v) : _val(v * MRATIO_UNIT)
{
}

Ratio::Ratio(double v) : _val(v * MRATIO_UNIT)
{
}

Ratio::Ratio(const Ratio &other) : _val(other._val)
{
}

Ratio		&Ratio::operator+=(const Ratio &other)
{
  _val += other._val;
  return (*this);
}

Ratio		&Ratio::operator-=(const Ratio &other)
{
  _val -= other._val;
  return (*this);
}

Ratio		Ratio::operator+(const Ratio &other) const
{
  return (Ratio(_val + other._val, 0));
}

Ratio		Ratio::operator-(const Ratio &other) const
{
  return (Ratio(_val - other._val, 0));
}

Ratio		&Ratio::operator%=(const Ratio &other)
{
  _val %= other._val;
  if (_val < 0)
    _val += other._val;
  return (*this);
}

Ratio		Ratio::operator%(const Ratio &other) const
{
  long			val = _val % other._val;

  if (_val < 0)
    val += other._val;
  return (Ratio(val, 0));
}

long		Ratio::longVal() const
{
  return (_val);
}

float		Ratio::floatVal() const
{
  return (_val / ((float)MRATIO_UNIT));
}

/***************/
/* COMPARISONS */
/***************/
bool		Ratio::operator==(const Ratio &other) const
{
  return (_val == other._val);
}

bool		Ratio::operator!=(const Ratio &other) const
{
  return (_val != other._val);
}

bool		Ratio::operator<(const Ratio &other) const
{
  return (_val < other._val);
}

bool		Ratio::operator<=(const Ratio &other) const
{
  return (_val <= other._val);
}

bool		Ratio::operator>(const Ratio &other) const
{
  return (_val > other._val);
}

bool		Ratio::operator>=(const Ratio &other) const
{
  return (_val >= other._val);
}

/******************/
/* INT OPERATIONS */
/******************/
Ratio	Ratio::operator*(const Distance &v) const
{
  return (Ratio(MTO_INT(_val * v.longVal()), 0));
}

Ratio	Ratio::operator/(const Distance &v) const
{
  return (Ratio(MTO_FLOAT(_val) / v.longVal(), 0));
}

Ratio	&Ratio::operator*=(const Distance &v)
{
  _val = MTO_INT(_val * v.longVal());
  return (*this);
}

Ratio	&Ratio::operator/=(const Distance &v)
{
  _val = MTO_FLOAT(_val) / v.longVal();
  return (*this);
}

std::ostream	&operator<<(std::ostream &s, Ratio const &a)
{
  s << a.floatVal();
  return (s);
}
