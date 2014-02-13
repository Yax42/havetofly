//
// Blast.cpp for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 27 22:47:57 2013 Brunier Jean
// Last update Mon Apr 29 14:45:57 2013 Brunier Jean
//

#include "Blast.hh"

Blast::Blast(const Player &player, const Angle &a) :
	AThrowable(player.bones()[Bones::FOOT2], Position(a, 10), 30, Position(a, 5), player)
{
	_hit.add(5, Position(), _pos);
}

void		Blast::move()
{
}

void		Blast::print(Graphics &g) const
{
	g.line(_pos - Position(_speed.angle(), 40), _pos, 0xFFffFF, 10);
	/*g.line(_pos - Position(_speed.angle(), 10) + Position (1, 1),
			_pos + Position (1, 1), 0xFFffFF);
	g.line(_pos - Position(_speed.angle(), 10) + Position (-1, -1),
			_pos + Position (-1, -1), 0xFFffFF);*/
}
