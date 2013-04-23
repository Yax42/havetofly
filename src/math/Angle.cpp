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

Angle::Angle(Ratio const &d) : _rad(d)
{
}

Angle::Angle(int deg, int) : _rad(Math::toRad(deg))
{
}
/*************/
/* OPERATORS */
/*************/
void	Angle::deg(int v)
{
  _rad = Math::toRad(v);
}

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

Angle		Angle::operator+(const Angle &other) const
{
  return (Angle(_rad + other._rad));
}

Angle		Angle::operator-(const Angle &other) const
{
  return (Angle(_rad - other._rad));
}


/***********/
/* GETTERS */
/***********/
Angle::operator Ratio() const
{
  return (_rad);
}

int		Angle::deg() const
{
  return (Math::toDeg(_rad.longVal()));
}

Ratio	Angle::rad()
{
  return (_rad);
}

Ratio const	&Angle::rad() const
{
  return (_rad);
}

Angle		Angle::mirrorX() const
{
  return (Math::acos(Math::cos(_rad)) *
      (Math::sin(_rad).longVal() < 0 ? 1 : -1));
}

Angle		Angle::mirrorY() const
{
  return (Math::acos(Math::cos(_rad) * (-1)) *
      (Math::sin(_rad).longVal() < 0 ? -1 : 1));
}

Angle		Angle::betweenX(Angle const &a, int sign) const
{
  //std::cout << *this << std::endl;
  Ratio		cur = MPOS_MOD(_rad + Angle(90, 0), Math::maxRad);
  Ratio		minR = Angle(90, 0) - a + (sign == 1 ? Angle() : Angle(180, 0));
  Ratio		maxR = Angle(90, 0) + a + (sign == 1 ? Angle() : Angle(180, 0));

  if (cur > maxR || cur < minR)
    {
      if (sign > 0)
	cur = ((cur > Angle(90, 0) && cur < Angle(270, 0)) ? maxR : minR);
      else
	cur = ((cur > Angle(90, 0) && cur < Angle(270, 0)) ? minR : maxR);
    }
  return (cur - Angle(90, 0));
}


std::ostream	&operator<<(std::ostream &s, Angle const &a)
{
  s << a.deg();
  return (s);
}
