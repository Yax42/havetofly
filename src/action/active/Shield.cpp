//
// Shield.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 01:05:50 2013 Brunier Jean
// Last update Sat Apr 20 10:49:18 2013 Brunier Jean
//

#include "Shield.hh"

Shield::Shield(Player &player) :
	AAction(player, SHIELD, new Hit(1, Position(-3, 0), player))
{
  _hit->add(50, Position(-5, 0), _bones[Bones::BODY]);
}

void	Shield::init(int)
{
  _count = 110;
  _player = Position();
  _player[DOUBLE_JUMP]->set(1);
}

bool	Shield::allow(int a)
{
  return (a > MOVE);
}

IAction		*Shield::step()
{
  if (_count--)
    return (this);
  return (_player[INERTIE]);
}

bool		Shield::request()
{
  return (_player[DOUBLE_JUMP]->val() &&
      	  _player.key[Key::X] == 1 &&
	  _player.key[Key::VERT] == 0);
}

void		Shield::upBones()
{
  _bones.angle[Bones::FOOT1] = Angle(0, 0);
  _bones.angle[Bones::FOOT2] = Angle(0, 0);
  _bones.angle[Bones::KNEE1] = Angle(MGRAD_CAP(MTIME * 2, 0, 50), 0);
  _bones.angle[Bones::KNEE2] = Angle(MGRAD_CAP(MTIME * 2 + 50, -50, 50), 0);

  _bones.angle[Bones::HAND1] = Angle(0, 0);
  _bones.angle[Bones::HAND2] = Angle(0, 0);
  _bones.angle[Bones::ELBOW1] = Angle(MGRAD_CAP(MTIME * 2, 65, 50), 0);
  _bones.angle[Bones::ELBOW2] = Angle(MGRAD_CAP(MTIME * 2 + 50, -115, 50), 0);

  _bones.angle[Bones::HEAD] = Angle(0, 0);
  _bones.angle[Bones::BODY] = Angle(0, 0);
}

void		Shield::check()
{
}

void		Shield::print(Graphics &g) const
{
  static const int	color[] =
    {
      0x0055FF,
      0xFFFFFF,
      0x0055FF
    };
  if (isActive())
    {
      for (int i = 0; i < 3; i++)
      {
	g.circle(_bones[Bones::BODY] + Position(-5, 0), 60 + i, color[i]);
      }
    }
}
