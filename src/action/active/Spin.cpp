//
// Spin.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 00:15:31 2013 Brunier Jean
// Last update Sat Apr 20 00:56:38 2013 Brunier Jean
//

#include "Spin.hh"

Spin::Spin(Player &player) :
	AAction(player, SPIN, new Hit(30, Position(0, 6), player))
{
  _hit->add(5, Position(), _player.bones()[Bones::FOOT1]);
  _hit->add(5, Position(), _player.bones()[Bones::FOOT2]);
  _hit->add(5, Position(), _player.bones()[Bones::HAND1]);
  _hit->add(5, Position(), _player.bones()[Bones::HAND2]);
}

void	Spin::init(int)
{
  _count = 100;
  _player = Position(0.5, 0);
}

bool	Spin::allow(int a)
{
  return (a == MOVE && _player.sy() >= 0);
}

IAction		*Spin::step()
{
  if (_count-- > 0 || _player.key(Key::X))
    return (this);
  return (_player[IAction::INERTIE]);
}

bool		Spin::request()
{
  return (_player.key[Key::X] == 1 && _player.key[Key::VERT] == 1);
}

void		Spin::upBones()
{
  _bones.angle[Bones::FOOT1] = Angle(10, 0);
  _bones.angle[Bones::FOOT2] = Angle(-5, 0);
  _bones.angle[Bones::KNEE1] = Angle(90, 0);
  _bones.angle[Bones::KNEE2] = Angle(-90, 0);

  _bones.angle[Bones::HAND1] = Angle(70, 0);
  _bones.angle[Bones::HAND2] = Angle(-60, 0);
  _bones.angle[Bones::ELBOW1] = Angle(MGRAD_CAP(MTIME*5, -130, 130), 0);
  _bones.angle[Bones::ELBOW2] = Angle(MGRAD_CAP(MTIME*5, 0, 130), 0);

  _bones.angle[Bones::HEAD] = Angle(0, 0);
  _bones.angle[Bones::BODY] = Angle(0, 0);
}

void		Spin::print(Graphics &g) const
{
  if (!isActive())
    return ;
  static const int	size = 30;
  static const int	color[] =
    {
      0xFF0000,
      0xFFFF00,
      0xFF4400,
      0xFF9900
    };
  int		goal =_player.orient() == -1 ? _bones[Bones::FOOT2].x() : _bones[Bones::FOOT1].x();
  for (int i = 0; i < 2; i++)
    for (Position i = (_player.orient() == 1 ? _bones[Bones::FOOT2] : _bones[Bones::FOOT1]);
        i.x() < goal; i.x(i.x() + 1))
      g.line(i, i + Position(15 + rand() % size - size / 2, rand() % size - size / 2), color[rand() % 4]);
}
