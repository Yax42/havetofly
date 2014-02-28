//
// Key.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 14 01:26:10 2013 Brunier Jean
// Last update Sun May 05 21:59:15 2013 Brunier Jean
//

#include "Math.hh"
#include "Key.hh"

#define	IGNORED_CAP 5000

Key::Key()
{
	_lastOkDir = Position(0, 1);
	for (int i = 0; i < COUNT; i++)
	{
		_delta[i] = 0;
		_prevVal[i] = 0;
	}
}

int	Key::operator[](int i) const
{
	if (i >= L2)
		return (_delta[i]);

	if (MPOS(*_val[i]) < IGNORED_CAP)
		return (0);
	if ((MPOS(*_val[VERT]) + 200 > MPOS(*_val[HOR])) == (i == VERT))
		return (MSIGN(*_val[i]));
	return (0);
}

int	Key::operator()(int i) const
{
	if (i <= VERT && *_val[i] > -IGNORED_CAP && *_val[i] < IGNORED_CAP)
		return (0);
	if (i == R2 || i == L2)
		return *_val[i] > 10000;
	return (*_val[i]);
}

void	Key::update()
{
	for (int i = L2; i < A; i++)
	{
		_delta[i] = (*_val[i] > 10000) - _prevVal[i];
		_prevVal[i] = *_val[i] > 10000;
	}
	for (int i = A; i < COUNT; i++)
	{
		_delta[i] = *_val[i] - _prevVal[i];
		_prevVal[i] = *_val[i];
	}

	float hor = 0;
	float vert = 0;
	if (MPOS(*_val[VERT]) >= IGNORED_CAP)
		vert = *_val[VERT];
	if (MPOS(*_val[HOR]) >= IGNORED_CAP)
		hor = *_val[HOR];
	if (vert != 0 || hor != 0)
		_lastOkDir = Position(vert, hor).normalize();
}

float	Key::squaredLength() const
{
	float hor = 0;
	float vert = 0;
	if (MPOS(*_val[VERT]) >= IGNORED_CAP)
		vert = *_val[VERT];
	if (MPOS(*_val[HOR]) >= IGNORED_CAP)
		hor = *_val[HOR];
	hor /= 0xFFFFFFFF;
	vert /= 0xFFFFFFFF;
	return (hor * hor + vert * vert);
}

float	Key::length() const
{
	return (Math::sqrt(squaredLength()));
}

int	Key::cur() const
{
	if (_delta[A] == 1)
		return (A);
	if (_delta[B] == 1)
		return (B);
	if (_delta[X] == 1)
		return (X);
	if (_delta[Y] == 1)
		return (Y);
	return (0);
}

int	*&Key::ptr(int i)
{
	return (_val[i]);
}

Angle		Key::angle() const
{
	return direction().angle();
}

Position		Key::direction() const
{
	return _lastOkDir;
}