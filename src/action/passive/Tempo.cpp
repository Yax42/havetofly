//
// Tempo.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 21 00:19:55 2013 Brunier Jean
// Last update Sun Apr 21 00:44:19 2013 Brunier Jean
//

#include "Tempo.hh"

Tempo::Tempo(Player &player) : AAction(player, TEMPO, NULL)
{
}

void		Tempo::init(int v)
{
  _open = v;
  _player = Position();
}

void		Tempo::set(int v)
{
  _count = v;
}

IAction		*Tempo::step()
{
  if (_count--)
    return (this);
  _player[_open]->init(1);
  return (_player[_open]);
}
