//
// Bones.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 17:23:55 2013 Brunier Jean
// Last update Wed Apr 10 17:35:32 2013 Brunier Jean
//

# include "Bones.hh"
# include "Charac.hh"

Bones::Bones(Charac const &charac) : _charac(charac)
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
//print
