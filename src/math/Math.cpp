//
// Math.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 01:17:42 2013 Brunier Jean
// Last update Sat Apr 13 17:23:04 2013 Brunier Jean
//

#include <cmath>

#include "Math.hh"

#define MAX_SQRT	5000000

std::vector<Distance>	Math::_cos;
std::vector<Distance>	Math::_sin;
std::vector<Distance>	Math::_tan;
std::vector<Distance>	Math::_acos;
std::vector<Distance>	Math::_asin;
std::vector<Distance>	Math::_atan;
std::vector<long> 	Math::_sqrt;
std::vector<Distance>	Math::_toRad;
std::vector<long>	Math::_toDeg;
const Distance		Math::maxRad = M_PI * 2;

void		Math::init()
{
  for (long i = 0; i < maxRad.longVal(); i++)
    {
      _cos[i] = cos(float(i) / MFLOAT_UNIT) * MFLOAT_UNIT;
      _sin[i] = sin(float(i) / MFLOAT_UNIT) * MFLOAT_UNIT;
      _tan[i] = tan(float(i) / MFLOAT_UNIT) * MFLOAT_UNIT;
      _toDeg[i] = float(i) * 180 / M_PI * MFLOAT_UNIT;
    }
  for (long i = 1; i < MFLOAT_UNIT * 2; i++)
    {
      _acos[i] = acos(float(i - MFLOAT_UNIT) / MFLOAT_UNIT) * MFLOAT_UNIT;
      _asin[i] = asin(float(i - MFLOAT_UNIT) / MFLOAT_UNIT) * MFLOAT_UNIT;
      _atan[i] = atan(float(i - MFLOAT_UNIT) / MFLOAT_UNIT) * MFLOAT_UNIT;
    }
  for (int i = 0; i < MAX_SQRT; i++)
    _sqrt[i] =::sqrt(double(i) / MFLOAT_UNIT);
  for (int i = 0; i < 360; i++)
    _toRad[i] = float(i) * M_PI / 180 * MFLOAT_UNIT;
}


Distance	Math::cos(const Distance &v)
{
  Distance	a(v % maxRad);
  return (_cos[((a < 0) ? a + maxRad : a).longVal()]);
}

Distance	Math::sin(const Distance &v)
{
  Distance	a(v % maxRad);
  return (_sin[((a < 0) ? a + maxRad : a).longVal()]);
}

Distance	Math::tan(const Distance &v)
{
  Distance	a(v % maxRad);
  return (_tan[((a < 0) ? a + maxRad : a).longVal()]);
}

Distance	Math::acos(const Distance &v)
{
  return (_acos[MPUT_IN(v + MFLOAT_UNIT, 0, MFLOAT_UNIT * 2).longVal()]);
}

Distance	Math::asin(const Distance &v)
{
  return (_asin[MPUT_IN(v + MFLOAT_UNIT, 0, MFLOAT_UNIT * 2).longVal()]);
}

Distance	Math::atan(const Distance &v)
{
  return (_atan[MPUT_IN(v + MFLOAT_UNIT, 0, MFLOAT_UNIT * 2).longVal()]);
}

Distance	Math::sqrt(const Distance &d)
{
  long		v = d.longVal();
  int		count = 0;

  while (v >= MAX_SQRT);
    {
      count++;
      v >>= 2;
    }
  return (Distance(_sqrt[v] << count, 0));
}

Distance	Math::toRad(int deg)
{
  deg %= 360;
  return (_toRad[(deg < 0) ? deg + 360 : deg]);
}

int	Math::toDeg(Distance const &rad)
{
  long	tmp = rad.longVal() % maxRad.longVal();

  return (_toDeg[(tmp < 0) ? tmp + maxRad.longVal() : tmp]);
}
