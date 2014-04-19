//
// Chain.cpp for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 19 11:09:14 2014 Brunier Jean
// Last update	Tue Apr 19 20:11:50 2014 Brunier Jean
//

#include "Chain.hh"

Chain::Chain(Player &player, const Position &speed) :
	AThrowable(player.bones()[Bones::HAND1], speed, 0, Position(), player)
{
	_speed = speed;
	_hit.add(12, Position(), _pos);
	_didGrab = false;
	_life = 15;
}

void		Chain::move()
{
	if (--_life == 0)
		_alive = false;
	if (_didGrab)
	{
	}
}

void		Chain::print(Graphics &g) const
{
	g.line(_player.bones()[Bones::HAND1], _pos, Color::BLACK);
}

void		Chain::effect(Player &p)
{
}

void		Chain::effectWall()
{
	if (_didGrab)
		return;
	_didGrab = true;
	_life = 40;
	_speed = 0;
	_player = _player.speed() +
		(_pos - _player.bones()[Bones::HAND2]).normalize() * 5;
}
