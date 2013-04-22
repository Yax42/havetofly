//
// HitCeiling.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 22 00:24:36 2013 Brunier Jean
// Last update Mon Apr 22 00:54:31 2013 Brunier Jean
//

#include "HitCeiling.hh"

HitCeiling::HitCeiling(Player &player) : PassiveAction(player, IAction::HIT_CEILING)
{
}

void		HitCeiling::check()
{
  if (_player(Event::CEILING) && _player.currentAction() != STICK_CEILING)
    {
      if (_player[TECH]->val())
        {
	  _player.sy(1);
	  _player.setAction(IAction::INERTIE);
	}
      else
        {
	  _player.setAction(IAction::STUN, 70);
	  _player.sy(3);
	  _player.sx(0);
	}
    }
}
