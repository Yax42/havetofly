//
// Hit.cpp for hit in /home/brunie_j/local/my/havetofly/src/hit
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:22:03 2013 Brunier Jean
// Last update Fri Apr 19 01:24:05 2013 Brunier Jean
//

#include <algorithm>

#include "Hit.hh"
#include "Player.hh"

Hit::Hit(int stun, Position const &speed, const Player &player) :
	_stun(stun), _speed(speed), _player(player)
{
}

void	Hit::add(const Distance &ray, const Position &center, const Position &playerPos)
{
  _hb.push_back(Hitbox(ray, center, playerPos, _player.orient()));
}

void	Hit::add(const Distance &ray, const Position &center)
{
  _hb.push_back(Hitbox(ray, center, _player.pos(), _player.orient()));
}

int	Hit::go(Player &ennemy) const
{
  ennemy.sy(_speed.yDist());
  ennemy.sx(_speed.xDist() * Distance(ennemy.orient()));
  return (_stun);
}

void	Hit::focus(Player &ennemy)
{
  for (std::list<Hitbox>::iterator i = _hb.begin(); i != _hb.end(); ++i)
    {
      if (&ennemy != &_player &&
	  std::find(_players.begin(), _players.end(), &ennemy) == _players.end() &&
	  i->touch(ennemy))
        {
  	  _players.push_back(&ennemy);
	  ennemy.hit(this);
	  break ;
        }
    }
}

void	Hit::reset()
{
  _players.clear();
}

void	Hit::print(Graphics &g) const
{
  for (std::list<Hitbox>::const_iterator i = _hb.begin(); i != _hb.end(); ++i)
    i->print(g, 0xFF0000);
}
