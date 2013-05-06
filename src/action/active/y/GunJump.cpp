//
// GunJump.cpp for throw in /home/brunie_j/local/my/havetofly/src/action/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 28 18:10:17 2013 Brunier Jean
// Last update Sun Apr 28 19:55:23 2013 Brunier Jean
//

#include "GunJump.hh"
#include "Blast.hh"

GunJump::GunJump(Player &player) : AAction(player, THROW_BALL, NULL)
{
}

void	GunJump::init(int)
{
  _count = 30;
  _player[AUTO_GUN]->set(-8);
  _player.sy(-3);
}

bool	GunJump::allow(int)
{
  return (false);
}

IAction		*GunJump::step()
{
  return (_player[INERTIE]);
}

bool		GunJump::request()
{
  return (_player[AUTO_GUN]->val() >= 8 &&
	  _player.key[Key::Y] == 1 &&
	  !_player.key(Key::R) &&
	  _player.key[Key::VERT] == -1 &&
	  _count == 0);
}

void		GunJump::upBones()
{
}

void		GunJump::check()
{
  if (_count)
    {
      if (_count % 7 == 0)
        _player.doThrow(new Blast(_player, Angle(90, 0)));
      _count--;
    }
}

void		GunJump::set(int)
{
}

int		GunJump::val()
{
  return (1);
}

void		GunJump::print(Graphics &g) const
{
  int		val;
  int		foot;

  if (_count)
    {
      for (int i = 0; i < 20; i++)
        {
	  foot = (rand() % 2) ? Bones::FOOT2 : Bones::FOOT1;
	  val = (rand() % (100 - _count + 2)) * 2;
	  g.circlePart(_bones[foot] + Position(Angle(90, 0), val), val,
	     Angle(-130, 0), Angle(80, 0), Color::fire[rand() % 4]);
	  g.line(_bones[foot],
	      _bones[foot] + Position(Angle(90, 0), val) + MRAND_POS_CI(30),
	      Color::fire[rand() % 4]);
	}
    }
}
