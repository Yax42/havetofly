//
// Math.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 01:17:42 2013 Brunier Jean
// Last update Tue Apr 23 00:34:08 2013 Brunier Jean
//

// http://www.cplusplus.com/reference/cmath/

#include <iostream>
#include <cmath>

#include "Math.hh"
#include "Angle.hh"
#include "Position.hh"

const float		Math::Pi = ((float)M_PI);
const float		Math::maxRad = Math::Pi * 2;
const float		Math::PiTwo = Math::Pi * 2;
const float		Math::PiHalf = Math::Pi / 2;


float	Math::sqrt(float v)
{
	return (::sqrt(v));
}

float		Math::toRad(float deg)
{

	return (deg * Math::Pi / 180);
}

float		Math::toDeg(float rad)
{
	return (rad * 180 / Math::Pi);
}

int		Math::abs(int v)
{
	return (::fabs((double)v));
}

float		Math::abs(float v)
{
	return (::fabs(v));
}

int			Math::cap(int x, int min, int max, bool stayIn)
{
	return (x < min + stayIn) ? min + stayIn : (x > max - stayIn) ? max + stayIn : x;
}

float		Math::cap(float x, float min, float max)
{
	return (x < min) ? min : (x > max) ? max : x;
}

int		Math::gradCap(int x, int min, int scale)
{
	return min + ((x % (scale * 2) >= scale) ? scale - (x % scale) - 1 : x % scale);
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

float	Math::atan2(float v1, float v2)
{
	return (::atan2(v1, v2));
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
	Position a;
	return (::atan(v));
}

float		Math::angle(const Position &from, const Position &to)
{
	if (from.squaredDistance() == 0 || to.squaredDistance() == 0)
		return 0;
	return acos(from.normalize().dot(to.normalize()));
}

float		Math::angle(const Position &pos)
{
	float res = angle(Position::UnitX, pos);
	if (pos.y < 0)
		res = -res;
	return res;
}