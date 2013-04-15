//
// Math.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 01:17:42 2013 Brunier Jean
// Last update Mon Apr 15 23:47:18 2013 Brunier Jean
//

#include <cmath>

#include "Math.hh"
#include <iostream>

#define MAX_SQRT	1000000

std::vector<Ratio>	Math::_cos;
std::vector<Ratio>	Math::_sin;
std::vector<Ratio>	Math::_tan;
std::vector<Ratio>	Math::_acos;
std::vector<Ratio>	Math::_asin;
std::vector<Ratio>	Math::_atan;
std::vector<long> 	Math::_sqrt;
std::vector<Ratio>	Math::_toRad;
std::vector<long>	Math::_toDeg;
const Ratio		Math::maxRad = M_PI * 2;

void		Math::init()
{
  _cos.resize(maxRad.longVal());
  _sin.resize(maxRad.longVal());
  _tan.resize(maxRad.longVal());
  _toDeg.resize(maxRad.longVal());
  for (long i = 0; i < maxRad.longVal(); i++)
    {
      _cos[i] = ::cos(double(i) / MRATIO_UNIT);
      _sin[i] = ::sin(double(i) / MRATIO_UNIT);
      _tan[i] = ::tan(double(i) / MRATIO_UNIT);
      _toDeg[i] = double(i) * 180 / M_PI / MRATIO_UNIT;
    }
  _acos.resize(MRATIO_UNIT * 2);
  _asin.resize(MRATIO_UNIT * 2);
  _atan.resize(MRATIO_UNIT * 2);
  for (long i = 0; i < MRATIO_UNIT * 2; i++)
    {
      _acos[i] = ::acos(double(i - MRATIO_UNIT) / MRATIO_UNIT);
      //std::cout << i << " " << _cos[(int)(i * M_PI * MFLOAT_UNIT / 180) ] << " " <<  _cos[(int)(i * M_PI * MFLOAT_UNIT / 180) ].doubleVal() * 1000 << std::endl;
      _asin[i] = ::asin(double(i - MRATIO_UNIT) / MRATIO_UNIT);
      _atan[i] = ::atan(double(i - MRATIO_UNIT) / MRATIO_UNIT);
    }
  _sqrt.resize(MAX_SQRT);
  for (int i = 0; i < MAX_SQRT; i++)
    _sqrt[i] =::sqrt(i);
    //_sqrt[i] =::sqrt(double(i) / MFLOAT_UNIT);
  _toRad.resize(360);
  for (int i = 0; i < 360; i++)
    {
      _toRad[i] = double(i) * M_PI / 180;
    }
}

Ratio	Math::cos(const Ratio &v)
{
  return (_cos[(v % maxRad).longVal()]);
}

Ratio	Math::sin(const Ratio &v)
{
  return (_sin[(v % maxRad).longVal()]);
}

Ratio	Math::tan(const Ratio &v)
{
  return (_tan[(v % maxRad).longVal()]);
}

Ratio	Math::acos(const Ratio &v)
{
  long		idx = v.longVal() + MRATIO_UNIT;
  return (_acos[MPUT_IN(idx, 0, 2 * MRATIO_UNIT)]);
}

Ratio	Math::asin(const Ratio &v)
{
  long		idx = v.longVal() + MRATIO_UNIT;
  return (_asin[MPUT_IN(idx, 0, 2 * MRATIO_UNIT)]);
}

Ratio	Math::atan(const Ratio &v)
{
  long		idx = v.longVal() + MRATIO_UNIT;
  return (_atan[MPUT_IN(idx, 0, 2 * MRATIO_UNIT)]);
}

Distance	Math::sqrt(const Distance &d)
{
  int		v = d.intVal();
  int		count = 0;

  while (v >= MAX_SQRT)
    {
      count++;
      v >>= 2;
    }
  //std::cout << v << " " << _sqrt[v] << std::endl;
  return (Distance(_sqrt[v] << count));
}

Ratio		Math::toRad(int deg)
{
  deg %= 360;
  return (_toRad[(deg < 0) ? deg + 360 : deg]);
}

int		Math::toDeg(Ratio const &rad)
{
  return (_toDeg[(rad % maxRad).longVal()]);
}
