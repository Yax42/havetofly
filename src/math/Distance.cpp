//
// Distance.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 11:27:34 2013 Brunier Jean
// Last update Fri Apr 12 16:32:39 2013 Brunier Jean
//

#include "Distance.hh"

#include "Math.hh"

/****************/
/* CONSTRUCTORS */
/****************/
Distance::Distance() : _val(0)
{
}

Distance::Distance(float v) : _val(v * MFLOAT_UNIT)
{
}

Distance::Distance(int v) : _val(MTO_FLOAT(v))
{
}

Distance::Distance(long v) : _val(v)
{
}

/****************/
/* AFFECTATIONS */
/****************/

Distance		&Distance::operator+=(const Distance &other)
{
  _val += other._val;
  return (*this);
}

Distance		&Distance::operator-=(const Distance &other)
{
  _val -= other._val;
  return (*this);
}

Distance		&Distance::operator*=(const Distance &other)
{
  _val = MUL_FLOAT(_val, other._val);
  return (*this);
}

Distance		&Distance::operator/=(const Distance &other)
{
  _val = (_val << MBIT_OS) / other._val;
  return (*this);
}

/**************/
/* OPERATIONS */
/**************/

Distance		Distance::operator+(const Distance &other) const
{
  return (Distance(_val + other._val));
}

Distance		Distance::operator-(const Distance &other) const
{
  return (Distance(_val - other._val));
}
Distance		Distance::operator*(const Distance &other) const
{
  return (MUL_FLOAT(_val, other._val));
}

Distance		Distance::operator/(const Distance &other) const
{
  return ((_val << MBIT_OS) / other._val);
}

/********/
/* CAST */
/********


Distance::operator int() const
{
  return (MTO_INT(_val));
}

Distance::operator long() const
{
  return (_val);
}

Distance::operator float() const
{
  return ((float(_val)) / MFLOAT_UNIT);
}

***********/
/* GETTERS */
/***********/

long		Distance::longVal() const
{
  return (_val);
}

int		Distance::intVal() const
{
  return (MTO_INT(_val));
}

float		Distance::floatVal() const
{
  return ((float(_val)) / MFLOAT_UNIT);
}
