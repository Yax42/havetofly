//
// Circle.cpp for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 15:59:09 2013 Brunier Jean
// Last update Sun Apr 14 16:55:56 2013 Brunier Jean
//

#include "Math.hh"
#include "Circle.hh"

Circle::Circle(const Position &center, const Distance &ray) :
	_center(center), _ray(ray)
{
}

Position	Circle::operator==(const Circle &other) const
{
  Position	center2 = other._center - _center +
    ((_center == other._center) ? 0.1 : 0);
  Distance	a = center2.xDist() * 2;
  Distance	b = center2.yDist() * 2;
  Distance	c = center2.xDist() *
		    center2.xDist() +
  		    center2.yDist() *
		    center2.yDist() -
		    other._ray * other._ray +
		    _ray * _ray;
  Distance	delta = (a * c * 2) * (a * c * 2) -
    (a * a + b * b) * (c * c - b * b * _ray * _ray) *  4;
  Distance	x = (a * c * 2 - Math::sqrt(delta)) / ((a * a + b * b) * 2);
  Distance	y;
  if (b == 0)
    y = (c - a * x) / b;
  else
    {
      Distance	tmp = (c * 2- a * a) / (a * 2);
      y = b / 2 + Math::sqrt(other._ray * other._ray - (tmp * tmp));
    }
  return (Position(y, x) + _center);
}
