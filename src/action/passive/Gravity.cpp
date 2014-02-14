//
// Gravity.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 11 00:07:50 2013 Brunier Jean
// Last update Sun May 05 13:40:27 2013 Brunier Jean
//

#include "Gravity.hh"

Gravity::Gravity(Player &player) : PassiveAction(player, GRAVITY)
{
}

bool		Gravity::request()
{
	static const float	MIN_SPEED(16);

	if (_player.sy() < MIN_SPEED)
		_player.sy(_player.sy() + 0.1); //2
	return (false);
}
