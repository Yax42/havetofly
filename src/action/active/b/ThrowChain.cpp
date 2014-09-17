//
// ThrowChain.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on Mon April 19 22:33:21 2014 Brunier Jean
// Last update Mon April 19 22:33:21 2014 Brunier Jean
//

#include "ThrowChain.hh"
#include "Game.hh"
#include "Chain.hh"

ThrowChain::ThrowChain(Player &player) :
	AAction(player, THROW_CHAIN, NULL)
{
	_usable = true;
}

void	ThrowChain::init(int v)
{
	_count = 20;
	Position dir;
	dir.x = (_player.orient() >= 0 ? 1 : -1);
	//dir.y = (_player.key(Key::VERT) >= 0 ? 1 : -1);
	dir.y = -1;
	_player.doThrow(new Chain(_player, dir * 10));
	_usable = false;
}

bool	ThrowChain::allow(int a)
{
	return allowPassive(a);
}

void	ThrowChain::step()
{
	_count--;
	if (_count == 40)
	{
	}
	else if (_count == 0)
	{
		_player.engageAction(INERTIE);
	}
}

void		ThrowChain::check()
{
	if (_player(Event::FREE_THROW))
		_usable = true;
}

bool		ThrowChain::request()
{
	return ((DEBUG & 1024 ||_usable) && _player.key[Key::X] == 1 && !_player.key(Key::R2));
}

int			ThrowChain::val()
{
	return 0;
}

void		ThrowChain::upBones()
{
}

void		ThrowChain::print(Graphics &g) const
{
	if (_usable)
	{
		Color color = _player.color();//0x0088FF;
		Color dif = _player.color();

		int			range = 24;
		int			iMax = range;
		float		delta = (float(range) / iMax);
		float		offset = 2;
		int			speed = 2;
		int			MaxRange = range * offset;
		int			angleRange(80);
		int			time = ((MTIME * speed) % (angleRange * 2));
		int			sign = 1;
		if (time > angleRange)
		{
			time -= angleRange;
			sign = -1;
		}
		time -= angleRange / 2;
		float	factor =1 - (Math::abs(float(time) / (angleRange / 2)));

		Angle		angle = _bones.angle[Bones::BODY] + Angle(0, 0);
		if (_player.orient() == 1)
			angle = angle.mirrorY();

		int limit = range / 2;
		for (int i = 0; i < iMax; i++)
		{
			color -= Color(0x03, 0x03, 0x03);

			for (int j = 0; j < 1; j++)
			{
				float	factor2 = 1;

				if (i < limit)
					factor2 = (i) / float(limit);

				g.circlePart(_bones[Bones::BODY], MaxRange - i * delta * offset,
					Angle(sign * (time + factor * (i - iMax) * 3), 0) + angle, Angle(27 * factor2, 0), color);
			}
		}
	}
}