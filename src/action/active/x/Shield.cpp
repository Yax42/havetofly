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

void		Shield::check()
{
	_count -= (_count < 0);
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

	Color		color = _player.color();//0x0088FF;
	Color		dif = _player.color();

	if (isActive())
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
}
