//
// Hit.cpp for hit in /home/brunie_j/local/my/havetofly/src/hit
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 11 00:22:03 2013 Brunier Jean
// Last update Mon May 06 17:35:59 2013 Brunier Jean
//

#include <algorithm>

#include "Hit.hh"
#include "Player.hh"

Hit::Hit(int stun, Position const &speed, const int &orient,
		int hitLagg, bool isThrowable, int type, bool addStun) :
	_stun(stun), _speed(speed), _orient(orient), _hitLagg(hitLagg),
	_isThrowable(isThrowable), _type(type), _addStun(addStun)
{
}

void	Hit::add(float ray, const Position &center, const Position &playerPos)
{
	_hb.push_back(Hitbox(ray, center, playerPos, _orient));
}


bool	Hit::isThrowable() const
{
	return (_isThrowable);
}

int	Hit::go(Player &ennemy) const
{
	if (_type != NONE)
	{
		ennemy.sy(_speed.y);
		ennemy.sx(_speed.x * ((_type == ORIENT) ? _orient : ennemy.closeWall()));
	}
	ennemy[IAction::HIT_LAGG]->init(_hitLagg);
	if (_addStun)
	{
		ennemy[IAction::STUN]->set(_stun);
		return (-1);
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

int	Hit::hitLagg() const
{
	return (_hitLagg);
}
