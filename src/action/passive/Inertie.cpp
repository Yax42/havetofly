//
// Inertie.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 11:31:46 2013 Brunier Jean
// Last update Wed Apr 17 19:18:44 2013 Brunier Jean
//

#include "Inertie.hh"

Inertie::Inertie(Player &player) : PassiveAction(player)
{
}

bool				Inertie::request()
{
  static const Distance 	PSLOW = 0.01;
  static const Distance 	MSLOW = -0.01;

  if (_player.sx() <= PSLOW && _player.sx() >= MSLOW)
    _player.sx(0);
  else if (_player.sx() < MSLOW)
    _player.sx(_player.sx() + PSLOW);
  else
    _player.sx(_player.sx() + MSLOW);
  return (false);
}

int		Inertie::id()
{
  return (IAction::INERTIE);
}

void		Inertie::upBones()
{
  Bones		&bones = _player.bones();

  if (0 && _player.sy() <= 0)
    {
      bones.angle[Bones::FOOT1] = Angle(-125, 0);
      bones.angle[Bones::FOOT2] = Angle(-120, 0);
      bones.angle[Bones::KNEE1] = Angle(120, 0);
      bones.angle[Bones::KNEE2] = Angle(130, 0);

      bones.angle[Bones::HAND1] = Angle(130, 0);
      bones.angle[Bones::HAND2] = Angle(120, 0);
      bones.angle[Bones::ELBOW1] = Angle(20, 0);
      bones.angle[Bones::ELBOW2] = Angle(25, 0);

      bones.angle[Bones::HEAD] = Angle(-90, 0);
      bones.angle[Bones::BODY] = Angle(22, 0);
    }
  else
    {

      bones.angle[Bones::FOOT1] = Angle(MGRAD_CAP(MTIME * 3, -80, 50), 0);
      bones.angle[Bones::FOOT2] = Angle(MGRAD_CAP(MTIME * 4, -80, 50), 0);
      bones.angle[Bones::KNEE1] = Angle(MGRAD_CAP(MTIME, -35, 30), 0);
      bones.angle[Bones::KNEE2] = Angle(MGRAD_CAP(MTIME, -65, 30), 0);

      bones.angle[Bones::HAND1] = Angle(MGRAD_CAP(MTIME * 3, 10, 50), 0);
      bones.angle[Bones::HAND2] = Angle(MGRAD_CAP(MTIME * 4, 10, 50), 0);
      bones.angle[Bones::ELBOW1] = Angle(MGRAD_CAP(MTIME, 195, 30), 0);
      bones.angle[Bones::ELBOW2] = Angle(MGRAD_CAP(MTIME, 225, 30), 0);

      bones.angle[Bones::HEAD] = Angle(-40, 0);
      bones.angle[Bones::BODY] = Angle(-80, 0);
      bones.angle[Bones::BODY] = Angle(60 - _player.sy().longVal() / 100 + MGRAD_CAP(MTIME / 4, -60, 20), 0);
      //bones.angle[Bones::BODY] = Angle(MGRAD_CAP(MTIME / 4, -60, 20), 0);
    }
}
