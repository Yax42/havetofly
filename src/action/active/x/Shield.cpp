//
// Shield.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 20 01:05:50 2013 Brunier Jean
// Last update Tue May 07 00:42:06 2013 Brunier Jean
//

#include "Shield.hh"
#include "Color.hh"

Shield::Shield(Player &player) :
	AAction(player, SHIELD, new Hit(90, Position(-2, 2), player.orient(), 10, false, Hit::WALL))
{
	_level = 0;
}

int		Shield::val()
{

	if (_count > 20);
		
	return (_open == 0);
}

void	Shield::init(int)
{
	_hit->reset();
	_open = 300;
	_count = 60;
	_prevSpeed = _player.speed();
	_player = Position();
	_player.invincible(true);
}

bool		Shield::request()
{
	return (_player.key[Key::Y] == 1 &&
			_player.key[Key::VERT] == 0 &&
			_player.key[Key::HOR] == 0);
}


void		Shield::end()
{
	_player.invincible(false);
	_player = _prevSpeed;
}

void		Shield::step()
{
	_count --;
	if (_count == 0)
	{
		_player.engageAction(INERTIE);
	}
}

void		Shield::set(int v)
{


}


void		Shield::print(Graphics &g) const
{
	static const int	nbParts = 3;
	Color	color2[] =
	{
		Color(_player.color()),
		0,
		Color(_player.color()),
		0xFFFFFF
	};

	if (isActive())
	{
		for (int i = 0; i < 4; i++)
			g.sponge(_bones[Bones::BODY], i + 60, 6, 3, Angle(MTIME * 4, 0), 0);
	}

#if 0
	Color		color = _player.color();//0x0088FF;
	Color		dif = _player.color();

	if (0 && isActive())
	{
		for (int i = 0; i < 32; i++)
		{
			color -= Color(0x08, 0x08, 0x08);

			for (int j = 0; j < nbParts; j++)
			{
				g.circlePart(_bones[Bones::BODY] + Position(-5, 0), 60 - i * 2,
					Angle(MTIME * 3 + i * 3 + j * 360 / nbParts, 0), Angle(30, 0), color);
			}

			for (int j = 0; j < nbParts; j++)
			{
				g.circlePart(_bones[Bones::BODY] + Position(-5, 0), 60 - i * 2,
					Angle(-MTIME * 3 - i * 3 - j * 360 / nbParts, 0), Angle(30, 0), color);
			}
		}
	}
	else if (_open == 0)
	{
		for (int i = 0; i < 7; i++)
			g.circle(_bones[Bones::HEAD], (MTIME / 5 + i) % 12 + 1, color2[(i) % 4].getInt());
	}


	return;


	color = _player.color();//0x0088FF;
	dif = _player.color();

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
	//if (time < 0); time = 0;
	float	factor =1 - (Math::abs(float(time) / (angleRange / 2)));

	Angle		angle = _bones.angle[Bones::BODY] + Angle(0, 0);
	if (_player.orient() == 1)
		angle = angle.mirrorY();

	int limit = range / 2;
	for (int i = 0; i < iMax; i++)
	{
		color -= Color(0x08, 0x08, 0x08);

		for (int j = 0; j < 1; j++)
		{
			float	factor2 = 1;

			if (i < limit)
				factor2 = (i) / float(limit);
			//if (i > limit) factor2 = 1 - (i - limit) / float(limit);

			g.circlePart(_bones[Bones::BODY], MaxRange - i * delta * offset,
			Angle(sign * (time + factor * (i - iMax) * 3), 0) + angle, Angle(27 * factor2, 0), color);
		}
	}
#endif

}
