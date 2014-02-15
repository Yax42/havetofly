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

HorDash::HorDash(Player &player) :
	AAction(player, HOR_DASH, new Hit(10, Position(8, 1), player.orient(), 10, false, Hit::WALL))
{
	_hit->add(20, Position(), _player.bones()[Bones::HEAD]);
}

void	HorDash::init(int v)
{
	if (0 && v == 0 && !PLANE_DEBUG)
		{
			_player.setAction(TEMPO, id());
			_player[TEMPO]->set(30000);
		}
	else
		{
			_hit->reset();
			_count = 30;
			//_player = Position(0, 6 * _player.orient());
			_player = _player.key.direction() * 3;
			_open = 0;
		}
}

void	HorDash::set(int)
{
	_open = 0;
}

bool	HorDash::allow(int a)
{
	return (a == DOWN_DASH || PLANE_DEBUG || a == CURVE);
}

IAction		*HorDash::step()
{
	if (_count-- == 0 ||
			(_player(Event::LEFT_WALL) && _player.orient() == -1) ||
			(_player(Event::RIGHT_WALL) && _player.orient() == 1))
		{
			_player.sx(_player.orient());
			return (_player[INERTIE]);
		}
	return (this);
}

bool		HorDash::request()
{
	return true;
	if (PLANE_DEBUG)
		return (_player.key[Key::HOR]);
	return (_open && !_player.key(Key::R) && _player.key[Key::X] == 1 && _player.key[Key::HOR]);
}

void		HorDash::check()
{
	if (_player(Event::WALL) && !isActive())
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
	_bones.angle[Bones::BODY] = Angle(_player.key.angle() + Math::PiHalf);
}

void		HorDash::print(Graphics &g) const
{
	g.line(_bones[Bones::HEAD], _bones[Bones::HEAD] + _player.key.direction() * 30, 
		Color::fire[rand() % 4]);
	if (_open)
	{
		for (int i = 0; i < 3; i++)
			g.sponge(_bones[Bones::HEAD], 13 + i * 2, 8, 5, Angle(MTIME * 2, 0), _player.color());
	}
	if (isActive())
	{
		for (int i = 0; i < 80; i++)
		{
			g.line(_bones[Bones::BODY], _bones[Bones::FOOT1] + MRAND_POS_CI(30),	Color::fire[rand() % 4]);
			g.circle(_bones[Bones::FOOT1] + MRAND_POS_CI(30), rand() % 15 + 3,	Color::fire[rand() % 4]);
		}
	}
}
