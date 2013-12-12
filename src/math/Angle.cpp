//
// Angle.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 09 17:16:14 2013 Brunier Jean
// Last update Tue Apr 23 17:22:16 2013 Brunier Jean
//

#include "Angle.hh"
#include "Math.hh"

/****************/
/* CONSTRUCTORS */
/****************/
Angle::Angle()
{
}

Angle::Angle(float d) : _rad(d)
{
}

Angle::Angle(float deg, int) : _rad(Math::toRad(deg))
{
}


//Angle::operator float() const { return (_rad); }



/*************/
/* OPERATORS */
/*************/
Angle		Angle::mirrorX() const
{
  return (Math::acos(Math::cos(_rad)) *
      (Math::sin(_rad) < 0 ? 1 : -1));
}

Angle		Angle::mirrorY() const
{
  return (Math::acos(Math::cos(_rad) * (-1)) *
      (Math::sin(_rad) < 0 ? -1 : 1));
}

Angle		Angle::betweenX(Angle const &a, int sign) const
{
  //std::cout << *this << std::endl;

  //# define MPOS_MOD(x, y)			(((x) % (y) < 0) ? (x) % (y) + (y) : (x) % (y))
  //float		cur = MPOS_MOD(_rad + Math::PiHalf, Math::maxRad);
  float		cur = _rad;

  float		tmpVal = Math::PiHalf + (sign != 1) * Math::Pi;
  float		minR = tmpVal - a._rad;
  float		maxR = tmpVal + a._rad;

  if (cur > maxR || cur < minR)
    {
      if (sign > 0)
	cur = ((cur > Math::PiHalf && cur < -Math::PiHalf) ? maxR : minR);
      else
	cur = ((cur > Math::PiHalf && cur < -Math::PiHalf) ? minR : maxR);
    }
  return (cur - Math::PiHalf);
}

Angle		Angle::operator+(Angle const &a) const
{
  return (a._rad + _rad);
}

 Angle		&Angle::operator+=(Angle const &a)
{
  _rad += a._rad;
  return (*this);
}

Angle		Angle::operator-(Angle const &a) const
{
  return (a._rad - _rad);
}

 Angle		&Angle::operator-=(Angle const &a)
{
  _rad -= a._rad;
  return (*this);
}

/**********/
/* ACCESS */
/**********/
void	Angle::deg(float v)
{
  _rad = Math::toRad(v);
}

void	Angle::rad(float v)
{
  _rad = v;
}

float		Angle::deg() const
{
  return (Math::toDeg(_rad));
}

float	Angle::rad() const
{
  return (_rad);
}

/* STREAM */

std::ostream	&operator<<(std::ostream &s, Angle const &a)
{
  s << a.deg();
  return (s);
}

