//
// Tech.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 11 00:55:33 2013 Brunier Jean
// Last update Sun May 05 18:36:51 2013 Brunier Jean
//

#include "Tech.hh"
#include "Player.hh"

Tech::Tech(Player &player) : PassiveAction(player, IAction::TECH)
{
}

void		Tech::check()
{
	_open -= (_open > 0);
	if (_count > 0)
		_count--;
	else if (_player.key[Key::L2] == 1 || _player.key[Key::R2] == 1)
		_count = 80;
}

int		Tech::val()
{
	if (_count >= 40)
		_open = 10;
	return (_count >= 40);
}

int		Tech::get(int v)
{
	return _count;
}

void		Tech::print(Graphics &g) const
{
	if (_open)
	{
		for (int i = 0; i < 6; i++)
		{
			g.sponge(_bones[Bones::FOOT1], 10 + i * 4 - _open * 2, 10, 10, Angle(MTIME * 2, 0), 0xFFFFFF);
		}
	}

	if (_count == 0 || (DEBUG & 16) == 0)
		return ;
	if (_count > 40)
		for (int j = 0; j < Bones::COUNT; j++)
			for (int i = 0; i < 10; i++)
				g.circle(_bones[j] + Position(-5, 0), 5 + i, 0x0000FF);
	else
		for (int j = 0; j < Bones::COUNT; j++)
			for (int i = 0; i < 10; i++)
				g.circle(_bones[j] + Position(-5, 0), 5 + i, 0xFF0000);
}
