//
// Spin.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 00:15:31 2013 Brunier Jean
// Last update Tue Apr 23 18:40:09 2013 Brunier Jean
//

#include "Spin.hh"

Spin::Spin(Player &player) :
	AAction(player, SPIN, new Hit(30, Position(0, 6), player.orient(), 10, false, Hit::WALL))
{
  _hit->add(5, Position(), _player.bones()[Bones::FOOT1]);
  _hit->add(5, Position(), _player.bones()[Bones::FOOT2]);
  _hit->add(5, Position(), _player.bones()[Bones::HAND1]);
  _hit->add(5, Position(), _player.bones()[Bones::HAND2]);
}

void	Spin::init(int)
{
  _hit->reset();
  _count = 50;
  _player = Position(0.7, 0);
}

bool	Spin::allow(int a)
{
  return (a == MOVE);
}

IAction		*Spin::step()
{
  if (_player.key[Key::VERT])
    _open = _player.key[Key::VERT];

  if (MPOS_MOD(_count, 50) == 0)
    _hit->reset();
  if (_count-- > 0 || _player.key(Key::X))
    return (this);
  return (_player[IAction::INERTIE]);
}

bool		Spin::request()
{

  //if (_player.key[Key::X])
    //std::cout <<  _player.key[Key::X]<< "a"<< std::endl;
  return (_player.key(Key::X) == 1 && _player.key[Key::VERT] > 0);
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
  _bones.angle[Bones::BODY] = Angle(90 - 90 * _open, 0);
}

void		Spin::print(Graphics &g) const
{
  if (!isActive())
    return ;
  static const int	size = 30;
  int	color[] =
    {
      (_player.color()),
      0,
      (_player.color()),
      0xFFFFFF,
      0x0000FF,
      0x00FFFF,
      0x0044FF,
      0x0099FF
    };
  int		goal =_player.orient() == -_open ? _bones[Bones::FOOT2].x() : _bones[Bones::FOOT1].x();
  for (int i = 0; i < 1; i++)
    for (Position i = (_player.orient() == _open ? _bones[Bones::FOOT2] : _bones[Bones::FOOT1]);
        i.x() < goal; i.x(i.x() + 1))
      g.line(i, i + Position((_open * 15) + rand() % size - size / 2, rand() % size - size / 2), color[rand() % 4]);
}
