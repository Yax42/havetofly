//
// Shield.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 01:05:50 2013 Brunier Jean
// Last update Mon Apr 22 01:48:57 2013 Brunier Jean
//

#include "Shield.hh"

Shield::Shield(Player &player) :
	AAction(player, SHIELD, new Hit(1, Position(-3, 0), player.orient()))
{
  _hit->add(50, Position(-5, 0), _bones[Bones::BODY]);
}

void	Shield::init(int)
{
  _open = 300;
  _count = 70;
  _player = Position();
}

bool	Shield::allow(int a)
{
  return (a > MOVE);
}

IAction		*Shield::step()
{
  _hit->reset();
  if (_count--)
    return (this);
  return (_player[INERTIE]);
}

bool		Shield::request()
{
  return (_open == 0 && _player.key[Key::X] == 1 &&
      _player.key[Key::VERT] == 0);
}

void		Shield::upBones()
{
  _bones.angle[Bones::FOOT1] = Angle(0, 0);
  _bones.angle[Bones::FOOT2] = Angle(0, 0);
  _bones.angle[Bones::KNEE1] = Angle(MGRAD_CAP(MTIME * 3, 0, 50), 0);
  _bones.angle[Bones::KNEE2] = Angle(MGRAD_CAP(MTIME * 3 + 50, -50, 50), 0);

  _bones.angle[Bones::HAND1] = Angle(0, 0);
  _bones.angle[Bones::HAND2] = Angle(0, 0);
  _bones.angle[Bones::ELBOW1] = Angle(MGRAD_CAP(MTIME * 3, 65, 50), 0);
  _bones.angle[Bones::ELBOW2] = Angle(MGRAD_CAP(MTIME * 3 + 50, -115, 50), 0);

  _bones.angle[Bones::HEAD] = Angle(0, 0);
  _bones.angle[Bones::BODY] = Angle(MTIME * 0, 0);
}

void		Shield::check()
{
  if (_open)
    _open--;
}

void		Shield::print(Graphics &g) const
{
  static const int	nbParts = 3;
  static const int	color2[] =
    {
      0x0000FF,
      0x00FFFF,
      0x0044FF,
      0x0099FF
    };
  int			color = 0x0088FF;
  if (isActive())
    {
      for (int i = 0; i < 32; i++)
      {
	  color -= 0x000408;

        for (int j = 0; j < nbParts; j++)
	{
  	  g.circlePart(_bones[Bones::BODY] + Position(-5, 0), 60 - i * 2,
	      Angle(MTIME * 3 + i * 3 + j * 360 / nbParts, 0), Angle(30, 0), color);
        }

        for (int j = 0; j < nbParts; j++)
	{
  	  g.circlePart(_bones[Bones::BODY] + Position(-5, 0), 60 - i * 2,
	      Angle(-MTIME * 3 - i * 3 - j * 360 / nbParts, 0), Angle(30, 0), color);
        }
      }
    }
  else if (_open == 0)
    {
      for (int i = 0; i < 7; i++)
	g.circle(_bones[Bones::HAND2], (MTIME / 5 + i) % 12 + 5, color2[(i) % 4]);
    }
}
