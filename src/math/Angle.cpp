//
// Angle.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 09 17:16:14 2013 Brunier Jean
// Last update Fri Apr 12 16:43:13 2013 Brunier Jean
//

#include "Angle.hh"
#include "Math.hh"

/****************/
/* CONSTRUCTORS */
/****************/
Angle::Angle() : _rad(0)
{
}

Angle::Angle(Distance const &d) : _rad(d)
{
}

Angle::Angle(int v) : _rad(Math::toRad(v))
{
}


/****************/
/* AFFECTATIONS */
/****************/

Angle		&Angle::operator+=(const Angle &other)
{
  _rad += other._rad;
  return (*this);
}

Angle		&Angle::operator-=(const Angle &other)
{
  _rad -= other._rad;
  return (*this);
}

Angle		&Angle::operator+=(int other)
{
  _rad += Math::toRad(MTO_FLOAT(other));
  return (*this);
}

Angle		&Angle::operator-=(int other)
{
  _rad -= Math::toRad(MTO_FLOAT(other));
  return (*this);
}

Angle		&Angle::operator=(int other)
{
  _rad = Math::toRad(MTO_FLOAT(other));
  return (*this);
}

Angle		&Angle::operator+=(float other)
{
  _rad += other * MFLOAT_UNIT;
  return (*this);
}

Angle		&Angle::operator-=(float other)
{
  _rad -= other * MFLOAT_UNIT;
  return (*this);
}

Angle		&Angle::operator=(float other)
{
  _rad = other * MFLOAT_UNIT;
  return (*this);
}

/**************/
/* OPERATIONS */
/**************/

Angle		Angle::operator+(const Angle &other) const
{
  return (Angle(_rad + other._rad));
}

Angle		Angle::operator-(const Angle &other) const
{
  return (Angle(_rad - other._rad));
}

Angle		Angle::operator+(int other) const
{
  return (Angle(Math::toDeg(_rad) + other));
}

Angle		Angle::operator-(int other) const
{
  return (Angle(Math::toDeg(_rad) - other));
}

Angle		Angle::operator+(float other) const
{
  return (Angle((float(_rad)) / MFLOAT_UNIT + other));
}

Angle		Angle::operator-(float other) const
{
  return (Angle((float(_rad)) / MFLOAT_UNIT - other));
}

/***********/
/* GETTERS */
/***********/

int		Angle::deg() const
{
  return (Math::toDeg(_rad));
}

float		Angle::rad() const
{
  return (((float) _rad) / MFLOAT_UNIT);
}
long		Angle::longVal() const
{
  return (_rad);
}

Distance	Angle::dist() const
{
  return (Distance(_rad));
}

