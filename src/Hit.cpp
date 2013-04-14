//
// Hit.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:22:03 2013 Brunier Jean
// Last update Sat Apr 13 21:13:53 2013 Brunier Jean
//

#include <algorithm>

#include "Hit.hh"
#include "Player.hh"

Hit::Hit(const Position &topL,
         const Position &botR,
         const Position &center,
         int stun, Distance speed, const Player &player) :
  _hb(topL, botR, center), _stun(stun), _speed(speed), _player(player)
{
}

Hit::~Hit()
{
}

int	Hit::go(Player &ennemy) const
{
  ennemy = _player.speed() * _speed;
  return (_stun);
}

void	Hit::focus(Player &ennemy)
{
  if (&ennemy != &_player &&
      std::find(_players.begin(), _players.end(), &ennemy) == _players.end() &&
      _hb.touch(ennemy))
    {
      _players.push_back(&ennemy);
      ennemy.hit(this);
    }
}

void	Hit::reset()
{
  _players.clear();
}
