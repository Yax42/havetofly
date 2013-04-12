//
// Hit.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:22:03 2013 Brunier Jean
// Last update Thu Apr 11 01:13:19 2013 Brunier Jean
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

void	focus(Player &ennemy)
{
  if (&ennemy != &_player && list.neContientPas(&ennemy))
    {
      ennemy = _speed * _player.pos();
      ennemy.stop();
      if (stun)
	ennemy.stun(50);

      _players.push_back(&ennemy);
    }
}

void	reset()
{
  _players//liberer la liste
}
