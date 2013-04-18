//
// DoubleJump.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 21:08:52 2013 Brunier Jean
// Last update Thu Apr 18 19:47:57 2013 Brunier Jean
//

#include "DoubleJump.hh"

DoubleJump::DoubleJump(Player &player) : AAction(player, NULL)
{
}

void	DoubleJump::init(int)
{
  _player.sy(-3.333);
  //_open = 0;
}

bool	DoubleJump::allow(int)
{
  return (false);
}

IAction		*DoubleJump::step()
{
  return (_player[IAction::INERTIE]);
}

bool		DoubleJump::request()
{
  return (_open && _player.key[Key::A] == 1);
}

int		DoubleJump::id()
{
  return (IAction::DOUBLE_JUMP);
}

void		DoubleJump::upBones()
{
}

void		DoubleJump::check()
{
}

void		DoubleJump::print(Graphics &g, const Bones &b) const
{
  if (_open)
    {
      g.sponge(b[Bones::FOOT1], 4, 5, 2, Angle(MTIME * 10, 0), (rand() % 2) * 0xFFFFFF);
      g.sponge(b[Bones::FOOT2], 4, 5, 2, Angle(MTIME * 10, 0), (rand() % 2) * 0xFFFFFF);
    }
}
