//
// Shield.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 01:05:50 2013 Brunier Jean
// Last update Tue Apr 23 20:03:17 2013 Brunier Jean
//

#include "Shield.hh"
#include "Color.hh"

Shield::Shield(Player &player) :
	AAction(player, SHIELD, new Hit(90, Position(-2, 2), player.orient(), 10, false, Hit::WALL))
{
  _hit->add(50, Position(-5, 0), _bones[Bones::BODY]);
  _hb.push_back(Hitbox(55, Position(-5, 0), _bones[Bones::BODY], _player.orient()));
}

void	Shield::init(int)
{
  _hit->reset();
  _open = 300;
  _count = 70;
  _player = Position();
}

bool	Shield::allow(int a)
{
  return (a > MOVE);
}


void	Shield::set(int)
{
  _open = 300;
}

IAction		*Shield::step()
{
  /*
  if (_count % 15 == 0)
    _hit->reset();
    */
  if (_count--)
    return (this);
  return (_player[INERTIE]);
}

bool		Shield::request()
{
  return (_open == 0 && _player.key[Key::B] == 1 &&
      _player.key[Key::VERT] == 0 &&
      _player.key[Key::HOR] == 0);
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
  Color	color2[] =
    {
      Color(_player.color()),
      0,
      Color(_player.color()),
      0xFFFFFF,
      0x0000FF,
      0x00FFFF,
      0x0044FF,
      0x0099FF
    };
  Color			color = _player.color();//0x0088FF;
  Color			dif = _player.color();
  if (isActive())
    {
      for (int i = 0; i < 32; i++)
      {
	  color -= Color(0x08, 0x08, 0x08);

        for (int j = 0; j < nbParts; j++)
	{
  	  g.circlePart(_bones[Bones::BODY] + Position(-5, 0), 60 - i * 2,
	      Angle(MTIME * 3 + i * 3 + j * 360 / nbParts, 0), Angle(30, 0), color.getInt());
        }

        for (int j = 0; j < nbParts; j++)
	{
  	  g.circlePart(_bones[Bones::BODY] + Position(-5, 0), 60 - i * 2,
	      Angle(-MTIME * 3 - i * 3 - j * 360 / nbParts, 0), Angle(30, 0), color.getInt());
        }
      }
    }
  else if (_open == 0)
    {
      for (int i = 0; i < 7; i++)
	g.circle(_bones[Bones::HEAD], (MTIME / 5 + i) % 12 + 1, color2[(i) % 4].getInt());
    }
}
