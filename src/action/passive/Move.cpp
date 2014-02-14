//
// Move.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 11 00:00:20 2013 Brunier Jean
// Last update Tue Apr 23 02:00:51 2013 Brunier Jean
//

#include "Move.hh"
#include "Player.hh"

Move::Move(Player &player) : PassiveAction(player, MOVE)
{
}

bool		Move::request()
{
	static const float 	MAX = 2;
	static const float 	MIN = -2;
	static const float	SPEED = 0.00007; //2/3

	if (_player.key(Key::HOR))
	{
		float newSx = _player.sx() + _player.key(Key::HOR) * SPEED;
		if (_player.key(Key::HOR) < 0)
			_player.orient(-1);
		else if (_player.key(Key::HOR) > 0)
			_player.orient(1);

		if (newSx > MAX && _player.sx() < MAX)
			_player.sx(MAX);
		if (newSx < MIN && _player.sx() > MIN)
			_player.sx(MIN);
		if (newSx >= MIN && newSx <= MAX)
			_player.sx(newSx);
	}
	return (false);
}
