//
// HorTP.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun May 05 18:44:24 2013 Brunier Jean
// Last update Sun May 05 19:01:09 2013 Brunier Jean
//

#include "HorTP.hh"

HorTP::HorTP(Player &player) :
	AAction(player, HOR_TP, NULL)
{
}

void	HorTP::init(int)
{
  _player[HOR_DASH]->set();
  _sign = _player.key[Key::HOR];
  _count = 3;
}

void	HorTP::set(int)
{
}

bool	HorTP::allow(int)
{
  return (false);
}

IAction		*HorTP::step()
{
  _player = Position(0, 0);
  _player.tp(Position(0, _sign * 40));
  if (_count--)
    return (this);
  return (_player[INERTIE]);
}

bool		HorTP::request()
{
  return (_player[HOR_DASH]->val() && _player.key(Key::R) &&
      _player.key[Key::B] == 1 && _player.key[Key::HOR]);
}

void		HorTP::check()
{
}

void		HorTP::upBones()
{
}

void		HorTP::print(Graphics &) const
{
}
