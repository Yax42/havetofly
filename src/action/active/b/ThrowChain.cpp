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
}

void	ThrowChain::init(int v)
{
	_count = 50;
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
		_player.doThrow(new Chain(_player, _player.key.direction() * 20));
	}
	else if (_count == 0)
	{
		_player.engageAction(INERTIE);
	}
}

void		ThrowChain::check()
{
}

bool		ThrowChain::request()
{
	return (_player.key[Key::X] == 1 && !_player.key(Key::R2));
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
}