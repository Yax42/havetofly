//
// DoubleJump.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 21:08:52 2013 Brunier Jean
// Last update Mon Apr 22 00:48:23 2013 Brunier Jean
//

#include "DoubleJump.hh"

DoubleJump::DoubleJump(Player &player) : AAction(player, DOUBLE_JUMP, NULL)
{
}

void	DoubleJump::init(int)
{
  _player.sy(-3.333);
  _open = 0;
}

bool	DoubleJump::allow(int)
{
  return (false);
}

IAction		*DoubleJump::step()
{
  return (_player[INERTIE]);
}

bool		DoubleJump::request()
{
  return (_open && _player.key[Key::A] == 1);
}

void		DoubleJump::upBones()
{
}

void		DoubleJump::check()
{
  if (_player(Event::HIT) || _player(Event::CEILING))
    _open = 1;
  if (DEBUG & 4)
    _open = 1;
}

void		DoubleJump::set(int v)
{
  _open = !v;
}

int		DoubleJump::val()
{
  return (_open);
}

void		DoubleJump::print(Graphics &g) const
{
  if (_open)
    {
      g.sponge(_bones[Bones::FOOT1], 4, 5, 2, Angle(MTIME * 10, 0), (rand() % 2) * 0xFFFFFF);
      g.sponge(_bones[Bones::FOOT2], 4, 5, 2, Angle(MTIME * 10, 0), (rand() % 2) * 0xFFFFFF);
    }
}
