//
// Line.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 12:27:53 2013 Brunier Jean
// Last update Sun Apr 14 13:37:55 2013 Brunier Jean
//

#include "Line.hh"

Line::Line(const Position &p1, const Position &p2)
{
  _a = (p2.yDist() - p1.yDist()) / (p2.xDist() - p1.xDist());
  _b = p1.yDist() - _a * p1.xDist();
}

Position	Line::operator==(const Line &other) const
{
  Distance	x = (_b - other._b) / (other._a - _a);

  return (Position(_a * x + _b, x));
}
