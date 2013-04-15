//
// Distance.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 11:27:34 2013 Brunier Jean
// Last update Mon Apr 15 23:27:50 2013 Brunier Jean
//

#include "Distance.hh"
#include "Angle.hh"

#include "Math.hh"

/****************/
/* CONSTRUCTORS */
/****************/
Distance::~Distance(){}

Distance::Distance()
{
}

Distance::Distance(float v) : _val(v * MFLOAT_UNIT)
{
}

Distance::Distance(double v) : _val(v * MFLOAT_UNIT)
{
}

Distance::Distance(int v) : _val(MTO_FLOAT(v))
{
}

Distance::Distance(long v) : _val(MTO_FLOAT(v))
{
}

Distance::Distance(long v, int) : _val(v)
{
}

Distance::Distance(Ratio const &rat) : _val(rat.longVal() >> MBIT_OS)
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
  _val = (_val << MBIT_OS) / (other._val ? other._val : 1);
  return (*this);
}

Distance		&Distance::operator%=(const Distance &other)
{
  _val %= other._val;
  if (_val < 0)
    _val += other._val;
  return (*this);
}

/**************/
/* OPERATIONS */
/**************/
Distance		Distance::operator+(const Distance &other) const
{
  return (Distance(_val + other._val, 0));
}

Distance		Distance::operator-(const Distance &other) const
{
  return (Distance(_val - other._val, 0));
}
Distance		Distance::operator*(const Distance &other) const
{
  return (Distance(MUL_FLOAT(_val, other._val), 0));
}

Ratio		Distance::operator/(const Distance &other) const
{
  //return (Distance((_val << MBIT_OS) / (other._val ? other._val : 1), 0));
  return ((_val << (MBIT_OS + MBIT_OS_RATIO)) / other._val);
}

Distance		Distance::operator%(const Distance &other) const
{
  long			val =_val % other._val;

  if (_val < 0)
    val += other._val;
  return (Distance(val, 0));
}

/***************/
/* COMPARISONS */
/***************/

bool		Distance::operator==(const Distance &other) const
{
  return (_val == other._val);
}

bool		Distance::operator!=(const Distance &other) const
{
  return (_val != other._val);
}

bool		Distance::operator<(const Distance &other) const
{
  return (_val < other._val);
}

bool		Distance::operator<=(const Distance &other) const
{
  return (_val <= other._val);
}

bool		Distance::operator>(const Distance &other) const
{
  return (_val > other._val);
}

bool		Distance::operator>=(const Distance &other) const
{
  return (_val >= other._val);
}

/*********/
/* RATIO */
/*********/

Distance		&Distance::operator*=(const Ratio &other)
{
  _val = (_val * other.longVal()) >> MBIT_OS_RATIO;
  return (*this);
}

Distance		&Distance::operator/=(const Ratio &other)
{
  _val = (_val << MBIT_OS_RATIO) / other.longVal();
  return (*this);
}

Distance		Distance::operator*(const Ratio &other) const
{
  return (Distance((_val * other.longVal()) >> MBIT_OS_RATIO, 0));
}

Distance		Distance::operator/(const Ratio &other) const
{
  return (Distance((_val << MBIT_OS_RATIO) / other.longVal(), 0));
}

/***********/
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

std::ostream	&operator<<(std::ostream &s, Distance const &d)
{
  s << d.intVal();
  return (s);
}
