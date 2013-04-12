//
// DoubleJump.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 21:08:52 2013 Brunier Jean
// Last update Thu Apr 11 00:02:51 2013 Brunier Jean
//

#include "DoubleJump.hh"
#include "Player.hh"

DoubleJump(const Player &player) : AAction (player, NULL)
{
}

DoubleJump::~DoubleJump()
{
}

int	DoubleJump::init()
{
  player.setYSpeed(30);
  _busy = 1;
}

bool	DoubleJump::allow(int a)
{
  return (true);
}

IAction		*DoubleJump::step()
{
  return (NULL);
}

bool		DoubleJump::request()
{
  return (!_busy && _player[K_JUMP]);
}

void		DoubleJump::check()
{
}
