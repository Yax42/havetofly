//
// HorTP.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun May 05 18:44:24 2013 Brunier Jean
// Last update Tue May 07 16:10:04 2013 Brunier Jean
//

#include "HorTP.hh"

HorTP::HorTP(Player &player) :
	AAction(player, HOR_TP, NULL)
{
}

void	HorTP::init(int)
{
  _pos = _player.pos() - Position(30, 30);
  _count = 20;
  _player[HOR_DASH]->set();
  _open = 1;
  _player = Position(0, 0);
  _player.tp(Position(0, _player.key[Key::HOR] * 150));
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
/*  if (_open)
    {
      _open--;
      return (this);
    }
  if (_player(Event::WALL))
    _player.tp(Position(50, 0));*/
  return (_player[INERTIE]);
}

bool		HorTP::request()
{
  return (_player[HOR_DASH]->val() && _player.key(Key::R) &&
      _player.key[Key::X] == 1 && _player.key[Key::HOR]);
}

void		HorTP::check()
{
  if (_count)
    _count--;
}

void		HorTP::upBones()
{
}

void		HorTP::print(Graphics &g) const
{
  if (_count)
    for (int i = 0; i < 80; i += (20 - _count))
      g.line(_pos + Position(i, rand() % 60),
 	     _pos + Position(i, rand() % 60), Color::BLUE);
}
