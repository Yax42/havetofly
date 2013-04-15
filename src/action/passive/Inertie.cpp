//
// Inertie.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 11:31:46 2013 Brunier Jean
// Last update Mon Apr 15 09:39:47 2013 Brunier Jean
//

#include "Inertie.hh"

Inertie::Inertie(Player &player) : PassiveAction(player)
{
}

bool		Inertie::request()
{
//  player.slowDown();
  return (false);
}

int		Inertie::id()
{
  return (IAction::INERTIE);
}

void		Inertie::upBones()
{
  Bones		&bones = _player.bones();

  //bones.angle[0] = Angle(MyTime::get(), 0);
  if (_player.sy() <= 0)
    {
      bones.angle[Bones::FOOT1] = Angle(-125, 0);
      bones.angle[Bones::FOOT2] = Angle(-120, 0);
      bones.angle[Bones::KNEE1] = Angle(120, 0);
      bones.angle[Bones::KNEE2] = Angle(130, 0);

      bones.angle[Bones::HAND1] = Angle(130, 0);
      bones.angle[Bones::HAND2] = Angle(120, 0);
      bones.angle[Bones::ELBOW1] = Angle(20, 0);
      bones.angle[Bones::ELBOW2] = Angle(25, 0);

      bones.angle[Bones::HEAD] = Angle(50, 0);
      bones.angle[Bones::BODY] = Angle(22, 0);
    }
  else
    {

      bones.angle[Bones::FOOT1] = Angle(-20, 0);
      bones.angle[Bones::FOOT2] = Angle(-50, 0);
      bones.angle[Bones::KNEE1] = Angle(-20, 0);
      bones.angle[Bones::KNEE2] = Angle(-50, 0);

      bones.angle[Bones::HAND1] = Angle(-30, 0);
      bones.angle[Bones::HAND2] = Angle(40, 0);
      bones.angle[Bones::ELBOW1] = Angle(200, 0);
      bones.angle[Bones::ELBOW2] = Angle(235, 0);

      bones.angle[Bones::HEAD] = Angle(0, 0);
      bones.angle[Bones::BODY] = Angle(-80, 0);
    }
}
