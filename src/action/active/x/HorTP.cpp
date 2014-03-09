//
// HorTP.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun May 05 18:44:24 2013 Brunier Jean
// Last update Tue May 07 16:10:04 2013 Brunier Jean
//

#include "HorTP.hh"

HorTP::HorTP(Player &player) :
	AAction(player, HOR_TP, NULL)
{
	_open = 220;
}

void	HorTP::init(int)
{
	_pos = _player.pos() - Position(30, 30);
	_open -= (_open - 40 >= 20) * 40;
	_count = 20;
	//_player[HOR_DASH]->set();
	_player = Position();
	_player.tp(Position(0, _player.key[Key::HOR] * _open));
}

void	HorTP::set(int)
{
}

bool	HorTP::allow(int)
{
	return (false);
}

void	HorTP::step()
{
/*	if (_open)
		{
			_open--;
			return (this);
		}
	if (_player(Event::WALL))
		_player.tp(Position(50, 0));*/
	_player.engageAction(INERTIE);
}

bool		HorTP::request()
{
	return (_player.key[Key::Y] == 1 && _player.key[Key::HOR]);
}

void		HorTP::check()
{
	_count -= (_count > 0);
}

void		HorTP::upBones()
{
}

void		HorTP::print(Graphics &g) const
{
	if (_count)
	{
		for (int i = 0; i < 40; i += (20 - _count))
			g.line(_pos + Position(i * 2, rand() % 60), _pos + Position(i * 2, rand() % 60), Color::BLUE);
	}
}
