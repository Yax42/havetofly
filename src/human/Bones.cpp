//
// Bones.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 17:23:55 2013 Brunier Jean
// Last update Sun Apr 14 11:30:18 2013 Brunier Jean
//

# include "Bones.hh"
# include "Graphics.hh"

Bones::Bones(const Position &centre, int color, int color2) :
	_center(centre), _color(color), _color2(color2)
{
}

Bones::~Bones()
{
}

void	Bones::foot1(Position const &pos)
{
  _foot1 = pos;
}

void	Bones::foot2(Position const &pos)
{
  _foot2 = pos;
}

void	Bones::hand1(Position const &pos)
{
  _hand1 = pos;
}

void	Bones::hand2(Position const &pos)
{
  _hand2 = pos;
}

void	Bones::body(Angle const &angle)
{
  _body = angle;
}

void	Bones::head(Angle const &angle)
{
  _head = angle;
}

void	Bones::print(Graphics &g) const
{
  g.circle(_center, 30, _color);
}
