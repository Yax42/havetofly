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
	_level = 3;
}

void	ThrowShuriken::init(int)
{
	_count = 40;
	_player.sy(Math::cap(_player.sy(), -5, _level == 0 ? 100 : -_level));
}

bool	ThrowShuriken::allow(int a)
{
	return (a == GRAVITY);
}

IAction		*ThrowShuriken::step()
{
	if (_count == 30)
		_player.doThrow(new Shuriken(_player, _player.pos(), _player.key.direction() * 10, _level--));
	if (_count--)
		return this;
	return (_player[INERTIE]);
}

bool		ThrowShuriken::request()
{
	return (_player.key[Key::B] == 1);
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
	return (_count < 0);
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
	g.sponge(_bones[Bones::HAND2], 5, 6, 3, Angle(MTIME * 8, 0), Shuriken::getColorFromLevel(_level));
	g.sponge(_bones[Bones::HAND2], 3, 6, 3, Angle(MTIME * 8, 0), Shuriken::getColorFromLevel(_level));

	if(1);
	else if (0&& !_open && _count < 20)
	{
		for (int i = 0; i < 4; i++)
			g.circle(_bones[Bones::HAND2], (20 - _count) / 2 + 1, 0);
	}
	else if (_count > 0)
	{
		for (int i = 0; i < 4; i++)
			g.sponge(_bones[Bones::HAND2], i + 1, 6, 3, Angle(MTIME * 3, 0), 0);
	}
}
