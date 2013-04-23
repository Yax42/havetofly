//
// ThrowShuriken.cpp for throw in /home/brunie_j/local/my/havetofly/src/action/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 23 11:58:18 2013 Brunier Jean
// Last update Tue Apr 23 17:24:07 2013 Brunier Jean
//

#include "ThrowShuriken.hh"
#include "Shuriken.hh"

ThrowShuriken::ThrowShuriken(Player &player) : AAction(player, THROW_SHURIKEN, NULL)
{
}

void	ThrowShuriken::init(int)
{
  if (_open == 0)
    _open = 450;
  else
    _count = 450;
  _player.doThrow(new Shuriken(_player));
  _player.sy(MCAP(_player.sy(), -5, 0));
}

bool	ThrowShuriken::allow(int)
{
  return (false);
}

IAction		*ThrowShuriken::step()
{
  return (_player[INERTIE]);
}

bool		ThrowShuriken::request()
{
  return ((!_open || !_count) && _player.key[Key::X] == 1 && !_player.key(Key::R));
}

void		ThrowShuriken::upBones()
{
}

void		ThrowShuriken::check()
{
  if (_count)
    _count--;
  if (_open)
    _open--;
}

void		ThrowShuriken::set(int)
{
}

int		ThrowShuriken::val()
{
  return (_open);
}

void		ThrowShuriken::print(Graphics &g) const
{
  if (!_count && !_open)
    {
      for (int i = 0; i < 4; i++)
        g.sponge(_bones[Bones::HAND2], (MTIME / 5 + i) % 6 + 1, 6, 3, Angle(MTIME * 3, 0), 0);
    }
  else if (!_count || !_open)
    {
      for (int i = 0; i < 4; i++)
	g.circle(_bones[Bones::HAND2], (MTIME / 5 + i) % 5 + 1, 0);
    }
}
