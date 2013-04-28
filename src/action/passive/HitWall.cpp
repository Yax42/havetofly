//
// HitWall.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 01:08:34 2013 Brunier Jean
// Last update Sat Apr 27 10:04:31 2013 Brunier Jean
//

#include "HitWall.hh"

HitWall::HitWall(Player &player) : PassiveAction(player, IAction::HIT_WALL)
{
}

void		HitWall::check()
{
  if (_player(Event::WALL))
    {

      if (_player.currentAction() == IAction::STUN)
        {
          if (_player[TECH]->val())
	    {
	      if (_player(Event::LEFT_WALL))
		_player = Position(-3.8, 2.4);
	      else if (_player(Event::RIGHT_WALL))
		_player = Position(-3.8, -2.4);
	      _player.orient(-_player.orient());
	      _player.setAction(IAction::INERTIE);
	    }
          else
	    {
	      _player[IAction::STUN]->set(70);
	      _player.sx(_player(Event::LEFT_WALL) ? 2 : -2);
	    }
	}
      else if ((_player(Event::LEFT_WALL) && _player.sx() < 0) ||
      	       (_player(Event::RIGHT_WALL) && _player.sx() > 0))
	_player.sx(0);
    }
}
