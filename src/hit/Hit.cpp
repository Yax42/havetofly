//
// Hit.cpp for hit in /home/brunie_j/local/my/havetofly/src/hit
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:22:03 2013 Brunier Jean
// Last update Mon Apr 22 01:45:19 2013 Brunier Jean
//

#include <algorithm>

#include "Hit.hh"
#include "Player.hh"

Hit::Hit(int stun, Position const &speed, const int &orient, int type) :
	_stun(stun), _speed(speed), _orient(orient), _type(type)
{
}

void	Hit::add(const Distance &ray, const Position &center, const Position &playerPos)
{
  _hb.push_back(Hitbox(ray, center, playerPos, _orient));
}

int	Hit::go(Player &ennemy) const
{
  if (_type != NONE)
    {
      ennemy.sy(_speed.yDist());
      ennemy.sx(_speed.xDist() *
	  (_type == ORIENT ? Distance(_orient) :
	   Distance(ennemy.closeWall())));
    }
  return (_stun);
}

bool	Hit::focus(Player &ennemy)
{
  for (std::list<Hitbox>::iterator i = _hb.begin(); i != _hb.end(); ++i)
    {
      if (std::find(_players.begin(), _players.end(), &ennemy) == _players.end() &&
	  i->touch(ennemy))
        {
  	  _players.push_back(&ennemy);
	  ennemy.hit(this);
	  return (true);
        }
    }
  return (false);
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
