//
// HitWall.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 01:08:34 2013 Brunier Jean
// Last update Wed Apr 17 23:54:55 2013 Brunier Jean
//

#include "HitWall.hh"

HitWall::HitWall(Player &player) : PassiveAction(player)
{
}

void		HitWall::check()
{
  if (_player(Event::WALL))
    {
      if (_player.currentAction() == IAction::STUN)
        {
          if (0) //action(0/*A_TECH*/).init())
	    _player.setAction(IAction::WALL_JUMP);
          else
	    {
	      _player[IAction::STUN]->set(50);
	      _player.sx(_player.sx() * Ratio(-1.2));
	    }
	}
      else if ((_player(Event::LEFT_WALL) && _player.sx() < 0) ||
      	       (_player(Event::RIGHT_WALL) && _player.sx() > 0))
	_player.sx(0);
    }
}

int		HitWall::id()
{
  return (HIT_WALL);
}
