//
// Color.cpp for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 22 18:01:03 2013 Brunier Jean
// Last update Mon Apr 22 18:25:02 2013 Brunier Jean
//

#include "Color.hh"

Color::Color(int col) : r((col >> 16) & 0xFF), g((col >> 8) & 0xFF), b(col & 0xFF)
{
}

Color::Color(int red, int blue, int green) : r(red), g(green), b(blue)
{
}

Color		&Color::operator-=(Color const &col)
{
  r -= col.r;
  if (r < 0)
    r = 0;
  g -= col.g;
  if (g < 0)
    g = 0;
  b -= col.b;
  if (b < 0)
    b = 0;
  return (*this);
}

Color		&Color::operator+=(Color const &col)
{
  r += col.r;
  if (r > 0xFF)
    r = 0xFF;
  g += col.g;
  if (g > 0xFF)
    g = 0xFF;
  b += col.b;
  if (b > 0xFF)
    b = 0xFF;
  return (*this);
}

Color		Color::operator/(int v) const
{
  return (Color(r / v, g / v, b / v));
}

Color		Color::operator*(int v) const
{
  Color		ret(*this);

  ret.r *= v;
  if (ret.r > 255)
    ret.r = 255;
  ret.g *= v;
  if (ret.g > 255)
    ret.g = 255;
  ret.b *= v;
  if (ret.b > 255)
    ret.b = 255;
  return (ret);
}

int		Color::getInt() const
{
  return ((r << 16) + (g << 8) + b);
}
