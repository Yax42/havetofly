//
// Hit.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:22:03 2013 Brunier Jean
// Last update Sat Apr 13 15:31:37 2013 Brunier Jean
//

#include "Hit.hh"

Hitbox		_hb;
std::list<Player *>	_players;
int			_stun;
Distance		_speed;
const Player		&_player;

Hit::Hit(const Position &topL,
         const Position &botR,
         const Position &center,
         int stun, Distance speed, const Player &player) :
  _hb(topL, botR, center), _stun(stun), _speed(speed) _player(player)
{
}

Hit::~Hit()
{
}

int	Hit::go()
{
  ennemy = _speed * _player.speed();
  return (_stun);
}

void	Hit::focus(Player &ennemy)
{
  if (&ennemy != &_player && list.neContientPas(&ennemy)
      && _hb.touch(ennemy))
    {
      _players.push_back(&ennemy);
      ennemy.hit(this);
    }
}

void	reset()
{
  _players.clear();
}
