//
// ThrowShuriken.cpp for b in /home/brunie_j/local/my/havetofly/src/action/active/b
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 23 11:58:18 2013 Brunier Jean
// Last update Mon May 06 22:34:30 2013 Brunier Jean
//

#include "ThrowShuriken.hh"
#include "Shuriken.hh"

ThrowShuriken::ThrowShuriken(Player &player) : AAction(player, THROW_SHURIKEN, NULL)
{
	_prevWasLevel3 = 0;
	_level = 3;
}

void	ThrowShuriken::init(int)
{
	_count = 40;
	_player.sy(Math::cap(_player.sy(), -5, _level == 0 ? 100 : -3));
}

bool	ThrowShuriken::allow(int a)
{
	return allowPassive(a);
}

void	ThrowShuriken::step()
{
	if (_count == 30)
	{
		if (!_prevWasLevel3 || _level != 3)
		{
			Position dir = _player.key.direction();
			if ((dir.x > 0) != (_player.orient() > 0))
			{
				dir.y = Math::signNoZero(dir.y);
				dir.x = 0;
			}

			_player.doThrow(new Shuriken(_player, _player.pos(), dir * 10, _level));
		}
		_prevWasLevel3 = (_level == 3);
		_level -= (_level > 0);
	}
	if (_count-- == 0)
		_player.engageAction(INERTIE);
}

bool		ThrowShuriken::request()
{
	return (_level > 0 && _player.key[Key::B] == 1 && ! _player.key(Key::R2));
}

void		ThrowShuriken::check()
{
	if (_player(Event::CEILING))
		_level = 3;
}

void		ThrowShuriken::set(int)
{
}

int		ThrowShuriken::val()
{
	return (_level);
}

/************/
/* GRAPHICS */
/************/
void		ThrowShuriken::upBones()
{
	Bones		&bones = _player.bones();

	bones.angle[Bones::FOOT1] = Angle(-125, 0);
	bones.angle[Bones::FOOT2] = Angle(-120, 0);
	bones.angle[Bones::KNEE1] = Angle(120, 0);
	bones.angle[Bones::KNEE2] = Angle(130, 0);

	bones.angle[Bones::HAND1] = Angle(130, 0);
	bones.angle[Bones::HAND2] = Angle(120, 0);
	bones.angle[Bones::ELBOW1] = Angle(20, 0);
	bones.angle[Bones::ELBOW2] = Angle(25, 0);

	bones.angle[Bones::HEAD] = Angle(-90, 0);
	bones.angle[Bones::BODY] = Angle(-MTIME * 16, 0);
}

void		ThrowShuriken::print(Graphics &g) const
{
	if (_level > 0)
	{
		g.sponge(_bones[Bones::HAND2], 5, 6, 3, Angle(MTIME * 8, 0), getColorFromLevel(_level));
		g.sponge(_bones[Bones::HAND2], 3, 6, 3, Angle(MTIME * 8, 0), getColorFromLevel(_level));
	}

	/*
	if (0&& !_open && _count < 20)
	{
		for (int i = 0; i < 4; i++)
			g.circle(_bones[Bones::HAND2], (20 - _count) / 2 + 1, 0);
	}
	*/
	if (_count > 0)
	{
		for (int i = 0; i < 4; i++)
			g.sponge(_bones[Bones::HAND2], i + 1, 6, 3, Angle(MTIME * 3, 0), 0);
	}
}
