//
// Math.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 01:17:42 2013 Brunier Jean
// Last update Wed Apr 10 12:37:58 2013 Brunier Jean
//

#include <cmath>

#include "Math.hh"

#define MAX_SQRT	5000000

std::vector<long>	Math::_cos;
std::vector<long>	Math::_sin;
std::vector<long>	Math::_tan;
std::vector<long>	Math::_acos;
std::vector<long>	Math::_asin;
std::vector<long>	Math::_atan;
std::vector<int> 	Math::_sqrt;
std::vector<long>	Math::_toRad;
std::vector<long>	Math::_toDeg;
long			Math::_maxRad;

void		Math::init()
{
  _maxRad = M_PI * 2 * MFLOAT_UNIT;
  for (long i = 0; i < _maxRad; i++)
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
    _sqrt[i] = ::sqrt(i);
  for (int i = 0; i < 360; i++)
    _toRad[i] = float(i) * M_PI / 180 * MFLOAT_UNIT;
}


long	Math::cos(long a)
{
  a %= _maxRad;
  return (_cos[((a < 0) ? a + _maxRad : a)]);
}

long	Math::sin(long a)
{
  a %= _maxRad;
  return (_sin[((a < 0) ? a + _maxRad : a)]);
}

long	Math::tan(long a)
{
  a %= _maxRad;
  return (_tan[((a < 0) ? a + _maxRad : a)]);
}

long	Math::acos(long v)
{
  v += MFLOAT_UNIT;
  return (_acos[MPUT_IN(v, 0, MFLOAT_UNIT * 2)]);
}

long	Math::asin(long v)
{
  v += MFLOAT_UNIT;
  return (_asin[MPUT_IN(v, 0, MFLOAT_UNIT * 2)]);
}

long	Math::atan(long v)
{
  v += MFLOAT_UNIT;
  return (_atan[MPUT_IN(v, 0, MFLOAT_UNIT * 2)]);
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
  return (Distance(_sqrt[v] << count));
}

long	Math::toRad(int deg)
{
  deg %= 360;
  return (_toRad[(deg < 0) ? deg + 360 : deg]);
}

int	Math::toDeg(long rad)
{
  rad %= _maxRad;
  return (_toDeg[(rad < 0) ? rad + _maxRad : rad]);
}
