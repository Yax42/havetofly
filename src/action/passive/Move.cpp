//
// Move.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:00:20 2013 Brunier Jean
// Last update Wed Apr 17 20:57:37 2013 Brunier Jean
//

#include "Move.hh"
#include "Player.hh"

Move::Move(Player &player) : PassiveAction(player)
{
}

bool		Move::request()
{
  static const Distance 	MAX = 2; //2/3
  static const Distance 	MIN = -2; //2/3
  static const Distance		SPEED = 0.0333; //2/3

  if (_player.key(Key::HOR))
    {
      _player.sx(_player.sx() + Distance(_player.key(Key::HOR), 0) * SPEED);
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

int		Move::id()
{
  return (IAction::MOVE);
}
