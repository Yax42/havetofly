//
// HitLagg.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 22 14:42:13 2013 Brunier Jean
// Last update Mon Apr 22 15:26:31 2013 Brunier Jean
//

#include "HitLagg.hh"

HitLagg::HitLagg(Player &player) : PassiveAction(player, HIT_LAGG)
{
}

void		HitLagg::init(int v)
{
  _count = v;
}

void		HitLagg::check()
{
  if (_count)
    _count--;
}

int		HitLagg::val()
{
  return (_count);
}
