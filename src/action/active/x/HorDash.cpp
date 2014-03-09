//
// HorDash.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 18 23:26:54 2013 Brunier Jean
// Last update Mon May 06 22:33:30 2013 Brunier Jean
//

#include "HorDash.hh"

const float		HorDash::_range = 200;

HorDash::HorDash(Player &player) :
	AAction(player, HOR_DASH, new Hit(10, Position(8, 1), player.orient(), 10, false, Hit::WALL))
{
//	_hit->add(20, Position(), _player.bones()[Bones::HEAD]);
}

void	HorDash::init(int v)
{
	if (v == 0 && !PLANE_DEBUG)
	{
		_player.setAction(TEMPO, id());
		_player[TEMPO]->set(10);
	}
	else
	{
		//_hit->reset();
		//_player = Position(0, 6 * _player.orient());
		_origin = _player.pos();
	}
}

void	HorDash::set(int)
{
	_open = 0;
}

bool	HorDash::allow(int a)
{
	return (a == DOWN_DASH
			|| PLANE_DEBUG
			|| a == CURVE
			|| (a == THROW_SHURIKEN && _player[THROW_SHURIKEN]->val() == 1));
}

void		HorDash::step()
{
	if (_origin.squaredDistance(_player.pos()) > _range * _range)
	{
		_player = Position(-3, _player.orient());
		_open = 0;
		_player.engageAction(INERTIE);
		return ;
	}
	if (_player(Event::WALL))
	{
		if (_player.sy() >= -2)
		{
			_player.engageAction(WALL_JUMP, -1);
		}
		else
		{
			_player = Position(-3, _player.orient());
			_player.engageAction(INERTIE);
		}
	}
	else
	{
		Position	speed = _player.key.direction() * 8;
		_player = speed;
		_player.orient((speed.x >= 0) - (speed.x < 0));
	}
}

bool		HorDash::request()
{
	if (PLANE_DEBUG)
		return true;
	return (_open && !_player.key(Key::R2) && _player.key[Key::X] == 1);
}

void		HorDash::check()
{
	if (_player(Event::WALL)
		&& !isActive())
		//&& (_player(Event::RIGHT_WALL) ^ (_player[HIT_WALL]->val() == 1)
		//|| _player[HIT_WALL]->val() == 0))
			_open = 1;
}

int		HorDash::val()
{
	return (_open);
}

/************/
/* GRAPHICS */
/************/
void		HorDash::upBones()
{
	_bones.angle[Bones::FOOT1] = Angle(0, 0);
	_bones.angle[Bones::FOOT2] = Angle(0, 0);
	_bones.angle[Bones::KNEE1] = Angle(0, 0);
	_bones.angle[Bones::KNEE2] = Angle(0, 0);

	_bones.angle[Bones::HAND1] = Angle(70, 0);
	_bones.angle[Bones::HAND2] = Angle(-60, 0);
	_bones.angle[Bones::ELBOW1] = Angle(-80, 0);
	_bones.angle[Bones::ELBOW2] = Angle(100, 0);

	_bones.angle[Bones::HEAD] = Angle(0, 0);
	_bones.angle[Bones::BODY] = Angle((_player.key.angle().rad() + Math::PiHalf) * (-_player.orient()));
}

void		HorDash::print(Graphics &g) const
{
	//g.line(_bones[Bones::HEAD], _bones[Bones::HEAD] + _player.key.direction() * 30, Color::fire[rand() % 4]);
	if (_open)
	{
		for (int i = 0; i < 3; i++)
			g.sponge(_bones[Bones::HEAD], 14 + i, 9, 3, _bones.angle[Bones::BODY].rad() * -_player.orient(), _player.color());
	}
	if (isActive())
	{
		for (int i = 0; i < 8; i++)
		{
			g.line(_bones[Bones::BODY], _bones[Bones::FOOT1] + MRAND_POS_CI(30),	Color::fire[rand() % 4]);
			g.circle(_bones[Bones::FOOT1] + MRAND_POS_CI(30), rand() % 15 + 3,	Color::fire[rand() % 4]);
		}
		g.circle(_origin, _range, _player.color());
	}
}
