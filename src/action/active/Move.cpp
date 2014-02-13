//
// Move.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:00:20 2013 Brunier Jean
// Last update Sun May 05 19:51:19 2013 Brunier Jean
//

#include "Move.hh"
#include "Player.hh"

Move::Move(Player &player) : PassiveAction(player, MOVE)
{
}

bool		Move::request()
{
  static const float 	MAX = 2; //2/3
  static const float 	MIN = -2; //2/3
  static const float		SPEED = 0.0333; //2/3

  if (_player.key(Key::HOR))
    {
      _player.sx(_player.sx() + MAX * SPEED);
      if (_player.key(Key::HOR) < 0)
	_player.orient(-1);
      else if (_player.key(Key::HOR) > 0)
	_player.orient(1);
      if (_player.sx() > MAX)
	_player.sx(MAX);
      if (_player.sx() < MIN)
	_player.sx(MIN);
    }
  return (false);
}
