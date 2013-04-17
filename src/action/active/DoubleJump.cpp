//
// DoubleJump.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 21:08:52 2013 Brunier Jean
// Last update Tue Apr 16 21:59:23 2013 Brunier Jean
//

#include "DoubleJump.hh"

DoubleJump::DoubleJump(Player &player) : AAction(player, NULL)
{
}

void	DoubleJump::init(int)
{
  *_player.key(Key::A) = 0;
  _player.sy(-5);
//  _open = 0;
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
  return (_open && *_player.key(Key::A));
}

int		DoubleJump::id()
{
  return (IAction::DOUBLE_JUMP);
}

void		DoubleJump::upBones()
{
}
