//
// Math.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 01:17:42 2013 Brunier Jean
// Last update Tue Apr 23 00:34:08 2013 Brunier Jean
//

// http://www.cplusplus.com/reference/cmath/

#include <iostream>
#include <cmath>

#include "Math.hh"
#include "Angle.hh"

const float		Math::maxRad = ((float)M_PI * 2);
const float		Math::Pi = ((float)M_PI);
const float		Math::PiTwo = ((float)M_PI * 2);
const float		Math::PiHalf = ((float)M_PI / 2);


float	Math::sqrt(float v)
{
  return (::sqrt(v));
}

float		Math::toRad(float deg)
{

  return (deg * (float)M_PI / 180);
}

float		Math::toDeg(float rad)
{
  return (rad * 180 / (float)M_PI);
}

int		Math::abs(int v)
{
  return (::fabs((double)v));
}

float		Math::abs(float v)
{
  return (::fabs(v));
}

/*******/
/*TRIGO*/
/*******/

float	Math::cos(const Angle &v)
{
  return (::cos(v.rad()));
}

float	Math::sin(const Angle &v)
{
  return (::sin(v.rad()));
}

float	Math::tan(const Angle &v)
{
  return (::tan(v.rad()));
}

float	Math::acos(const Angle &v)
{
  return (::acos(v.rad()));
}

float	Math::asin(const Angle &v)
{
  return (::asin(v.rad()));
}

float	Math::atan(const Angle &v)
{
  return (::atan(v.rad()));
}

//----------------------------------------------

float	Math::cos(float v)
{
  return (::cos(v));
}

float	Math::sin(float v)
{
  return (::sin(v));
}

float	Math::tan(float v)
{
  return (::tan(v));
}

float	Math::acos(float v)
{
  return (::acos(v));
}

float	Math::asin(float v)
{
  return (::asin(v));
}

float	Math::atan(float v)
{
  return (::atan(v));
}

