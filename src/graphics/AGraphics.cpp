//
// AGraphics.cpp for AGraphics in /home/berton_s//tech2/Nibbler/nibbler/src
//
// Made by sebastien berton
// Login   <berton_s@epitech.net>
//
/* Started on  Tue Mar  5 17:57:06 2013 sebastien berton
** Last update Sat Mar 16 22:08:43 2013 Brunier Jean
*/

#include <iostream>

#include "AGraphics.hh"


AGraphics::AGraphics() : _isFinish(false)
{
}

AGraphics::~AGraphics()
{
}

void		AGraphics::square(Position const &pos1, Position const &pos3, int color)
{
  Position	tmp((pos3 - pos1) / 2);
  Position	pos2(Position(tmp.angle() + 90, tmp.distance(), 0) + tmp + pos1);
  Position	pos4(Position(tmp.angle() - 90, tmp.distance(), 0) + tmp + pos1);

  AGraphics::line(pos1, pos2, 0, color);
  AGraphics::line(pos3, pos2, 0, color);
  AGraphics::line(pos3, pos4, 0, color);
  AGraphics::line(pos1, pos4, 0, color);
}

void		AGraphics::squareSpiral(Position pos1, Position pos2, int delta, int size, int color)
{
  int		angle = 90;
  Position	tmp;

  line(pos1, pos2, 0, color);
  for (int i = 0; i < size; i++)
    {
      tmp = pos2 - pos1;
      pos2 = pos1;
      pos1 -= Position(angle, tmp.distance() - delta * ((i > 2) ? (i) % 2 == 1 : 0), 0);
      line(pos1, pos2, 0, color);
      angle += 90;
    }
}

void		AGraphics::squareCeption(Position pos1, Position pos3, int delta, int size, int color)
{
  Position	tmp((pos3 - pos1) / 2);
  Position	pos2(Position(tmp.angle() + 90, tmp.distance(), 0) + tmp + pos1);
  Position	pos4(Position(tmp.angle() - 90, tmp.distance(), 0) + tmp + pos1);

  for (int i = 0; i < size; i++)
    {
      tmp = pos1;
      pos1 = pos1.between(pos2, delta);
      pos2 = pos2.between(pos3, delta);
      pos3 = pos3.between(pos4, delta);
      pos4 = pos4.between(tmp, delta);
      line(pos1, pos2, 0, color);
      line(pos2, pos3, 0, color);
      line(pos3, pos4, 0, color);
      line(pos4, pos1, 0, color);
      color += 0x2020;
    }
}

void		AGraphics::star(Position const &center, int angle, int delta, int size, int color)
{
  Position	pos1;
  Position	pos2;
  int		deltaAngle = 360 * (size / 2) / size;

  if (size < 3)
    return ;
  pos1 = Position(angle, delta, 0);
  for (int i = 0; i < 2 * size; i++)
    {
      pos2 = Position(pos1.angle() + deltaAngle, delta, 0);
      line(pos1 + center, pos2 + center, 0, color);
      pos1 = pos2;
    }
}

void		AGraphics::sponge(Position const &pos, int ray, int nb, int size, int angle, int color)
{
  float		angleOffset = 360.0 / nb;
  Position	pos1;
  Position	pos2;

  for (float i = angle; i < 360 + angle; i += angleOffset)
    {
      pos1 = Position(i, ray - size, 0) + pos;
      pos2 = Position(i + angleOffset / 2, ray + size, 0) + pos;
      line(pos1, pos2, 0, color);
      pos1 = Position(i + angleOffset, ray - size, 0) + pos;
      line(pos2, pos1, 0, color);
    }
}

void		AGraphics::triangleCeption(Position const &pos1, Position const &pos2, Position const &pos3, int delta, int size, int color)
{
  color |= 0x8080f0;

  privateTriangleCeption(pos1, pos2, pos3, delta, size, color);
  line(pos1, pos2, 0, color);
  line(pos3, pos1, 0, color);
}

void		AGraphics::privateTriangleCeption(Position const &pos1, Position const &pos2, Position const &pos3, int delta, int size, int color)
{
  if (size == 0)
    return ;
  line(pos2, pos3, 0, color);
  color /= 2;
  color |= 0x6060f0;
  privateTriangleCeption(pos1, pos1.between(pos2, delta), pos3.between(pos1, delta), delta, size - 1, color);
  privateTriangleCeption(pos2, pos2.between(pos3, delta), pos1.between(pos2, delta), delta, size - 1, color);
  privateTriangleCeption(pos3, pos3.between(pos1, delta), pos2.between(pos3, delta), delta, size - 1, color);
}

void		AGraphics::circle(Position const &pos, int size, int color)
{
  int		max;
  Position	pxPos;

  max = Position::PI * 2 * size;
  for (int i = 0; i < max; i++)
    {
      pxPos.x = cos(float(i) / size) * size;
      pxPos.y = sin(float(i) / size) * size;
      pxPos += pos;
      printPixel(pxPos, color);
    }
}

void		AGraphics::line(Position const &pos1, Position const &pos2, int camber, int color)
{
  Position	vect = pos2 - pos1;
  int		angle = vect.angle();
  int		range = vect.distance();

  for (int i = 0; i <= range; i++)
    printPixel(pos1 + Position(angle, i, 0), color);
  (void) camber;
}

void	AGraphics::spiral(Position const &pos, int angle, int delta, int size, int color)
{
  Position	px;

  for (int i = 0; i < size; i++)
    {
      px.x = cos(Position::toRad(i + angle)) * i * delta / 1000;
      px.y = sin(Position::toRad(i + angle)) * i * delta / 1000;
      px += pos;
      printPixel(px, color);
    }
}

void  AGraphics::spiral(Position const &pos, int angle, int delta, int size, long color1, long color2)
{
  Position	px;

  for (int i = 0; i < size; i++)
    {
      px.x = cos(Position::toRad(i + angle)) * i * delta / 1000;
      px.y = sin(Position::toRad(i + angle)) * i * delta / 1000;
      px += pos;
      printPixel(px, (color2 * i + color1 * (size - i)) / size);
    }
}

void		AGraphics::rotCircle(Position const &first, int size, int color, std::list<Position> const &centers)
{
  Position	center(first);

  for (std::list<Position>::const_iterator i = centers.begin(); i != centers.end(); ++i)
    center += *i;
  circle(center, size, color);
}

bool	AGraphics::isFinish() const
{
  return (_isFinish);
}
