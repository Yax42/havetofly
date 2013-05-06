//
// DeathRay.cpp for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun May 05 13:56:48 2013 Brunier Jean
// Last update Sun May 05 16:20:11 2013 Brunier Jean
//

#include "DeathRay.hh"

DeathRay::DeathRay(const Player &player, const Angle &a) :
	AThrowable(player.pos(), RatioPosition(a, 6), 30, Position(1, 1), player),
	_player(NULL)
{
  _hit.add(20, Position(), _pos);
}

void		DeathRay::move()
{
}

void		DeathRay::effect(Player &p)
{
  if (_player == NULL)
    _player = &p;
}

void		DeathRay::print(Graphics &g) const
{
  g.circleFull(_pos, 13, 0xFFFF00);
}
