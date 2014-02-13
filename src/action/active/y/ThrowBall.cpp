//
// ThrowBall.cpp for throw in /home/brunie_j/local/my/havetofly/src/action/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 23 03:11:39 2013 Brunier Jean
// Last update Tue Apr 23 18:06:31 2013 Brunier Jean
//

#include "ThrowBall.hh"
#include "Ball.hh"

ThrowBall::ThrowBall(Player &player) : AAction(player, THROW_BALL, NULL)
{
}

void	ThrowBall::init(int)
{
	_open = 10;
	for (int i = -80; i > -100; i -= 5)
		_player.doThrow(new Ball(_player, Angle(i, 0)));
}

bool	ThrowBall::allow(int)
{
	return (false);
}

IAction		*ThrowBall::step()
{
	return (_player[INERTIE]);
}

bool		ThrowBall::request()
{
	return (false && !_open && _player.key[Key::X] == 1 && _player.key(Key::R));
}

void		ThrowBall::upBones()
{
}

void		ThrowBall::check()
{
	if (_open)
		_open--;
}

void		ThrowBall::set(int)
{
}

int		ThrowBall::val()
{
	return (_open);
}

void		ThrowBall::print(Graphics &) const
{
}
