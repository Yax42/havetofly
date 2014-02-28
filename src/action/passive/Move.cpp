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
	static const float 	MAX = 3;
	static const float 	MIN = -3;
	static const float	SPEED = 0.000003; //2/3

	if (_player.key(Key::HOR))
	{
		float	curSx = _player.sx();
		float	newSx = curSx + _player.key(Key::HOR) * SPEED;
		if (_player.key(Key::HOR) < 0)
			_player.orient(-1);
		else if (_player.key(Key::HOR) > 0)
			_player.orient(1);

		if (newSx > MAX && curSx < MAX)
			_player.sx(MAX);
		else if (newSx < MIN && curSx > MIN)
			_player.sx(MIN);
		else if ((newSx >= MIN && newSx <= MAX)
			|| (newSx < MIN && curSx < newSx)
			|| (newSx > MAX && curSx > newSx))
				_player.sx(newSx);
	}
	return (false);
}
