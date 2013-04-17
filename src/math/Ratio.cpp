//
// Ratio.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 15 14:02:52 2013 Brunier Jean
// Last update Tue Apr 16 01:03:36 2013 Brunier Jean
//

#include "Ratio.hh"
#include "Math.hh"

Ratio::Ratio() : _val(0)
{
}

Ratio::Ratio(long v) : _val(v)
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
  return (_val + other._val);
}

Ratio		Ratio::operator-(const Ratio &other) const
{
  return (_val - other._val);
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
  long			val =_val % other._val;

  if (_val < 0)
    val += other._val;
  return (val);
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
Ratio	Ratio::operator*(int v) const
{
  return (_val * v);
}

Ratio	Ratio::operator/(int v) const
{
  return (_val * v);
}


std::ostream	&operator<<(std::ostream &s, Ratio const &a)
{
  s << a.floatVal();
  return (s);
}
