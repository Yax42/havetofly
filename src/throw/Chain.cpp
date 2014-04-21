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
	_life = 30;
	_grabbedHuman = false;
}

void		Chain::move()
{
	if (--_life == 0)
		_alive = false;
	if (_didGrab)
	{
		if (_grabbedHuman)
		{
			_pos = _victim->pos();
		}
	}
}

void		Chain::effect(Player &p)
{
	if (_didGrab)
		return;
	_didGrab = true;
	_grabbedHuman = true;
	_victim = &p;
	_life = 40;
	_speed = 0;
	Position dir = (_pos - _player.bones()[Bones::HAND2]).normalize();

	_player.sx(_player.sx() + dir.x * 5);
	_player.sy(dir.y * 5);

	p.sx(p.sx() + -dir.x * 5);
	p.sy(-dir.y * 5);
}

void		Chain::effectWall()
{
	if (_didGrab)
		return;
	_didGrab = true;
	_life = 40;
	_speed = 0;
	Position dir = (_pos - _player.bones()[Bones::HAND2]).normalize();
	//_player = _player.speed() + (_pos - _player.bones()[Bones::HAND2]).normalize() * 5;
	_player.sx(_player.sx() + dir.x * 5);
	_player.sy(dir.y * 5);
}

void		Chain::print(Graphics &g) const
{
	static const float ray = 10;

	Position	dir = (_pos - _player.bones()[Bones::HAND1]);
	Position	dirNorm = dir.normalize();
	Angle		dirAngle = dirNorm.angle();

	Position p1 = _pos - (dirNorm * ray);
	float didGrabFactor = _didGrab ? 1 : 2;
	Position p2 = p1 + Position(dirAngle - Angle(45, 0), ray * didGrabFactor);
	Position p3 = p1 + Position(dirAngle + Angle(45, 0), ray * didGrabFactor);
	if (_didGrab)
	{
		Position p4 = _pos + (dirNorm * ray);
		g.line(p4, p2, Color::BLACK);
		g.line(p4, p3, Color::BLACK);
	}

	g.line(_player.bones()[Bones::HAND1], p1, Color::BLACK);
	g.line(p1, p2, Color::BLACK);
	g.line(p1, p3, Color::BLACK);
}