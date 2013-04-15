//
// Move.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:00:20 2013 Brunier Jean
// Last update Sun Apr 14 22:32:57 2013 Brunier Jean
//

#include "Move.hh"
#include "Player.hh"

Move::Move(Player &player) : PassiveAction(player)
{
}

bool		Move::request()
{
  if (*_player.key(Key::HOR))
    {
      _player.sx(_player.sx() + Distance(*_player.key(Key::HOR), 0));
    }
  return (false);
}

int		Move::id()
{
  return (IAction::MOVE);
}
