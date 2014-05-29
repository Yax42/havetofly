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
	_lastOkDir[0] = Position(0, 1);
	_lastOkDir[1] = Position(0, 1);
	for (int i = 0; i < COUNT; i++)
	{
		_delta[i] = 0;
		_prevVal[i] = 0;
	}
}

int	Key::operator[](int i) const
{
	if (i <= LAST_ANALOG)
	{
		if (MPOS(*_val[i]) < IGNORED_CAP)
			return 0;
		if (i == VERT || i == HOR)
		{
			if ((MPOS(*_val[VERT]) + 200 > MPOS(*_val[HOR])) == (i == VERT))
				return (MSIGN(*_val[i]));
			else
				return 0;
		}
		else
		{
			if ((MPOS(*_val[VERT2]) + 200 > MPOS(*_val[HOR2])) == (i == VERT2))
				return (MSIGN(*_val[i]));
			else
				return 0;
		}
	}
	else
		return (_delta[i]);
}

int	Key::operator()(int i) const
{
	if (i <= LAST_ANALOG && MPOS(*_val[i]) < IGNORED_CAP)
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

	for (int i = 0; i < 4; i += 2)
	{
		float hor = 0;
		float vert = 0;
		if (MPOS(*_val[VERT + i]) >= IGNORED_CAP)
			vert = *_val[VERT + i];
		if (MPOS(*_val[HOR + i]) >= IGNORED_CAP)
			hor = *_val[HOR + i];
		if (vert != 0 || hor != 0)
			_lastOkDir[i / 2] = Position(vert, hor).normalize();
	}
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

Angle		Key::angle(int id) const
{
	return direction(id).angle();
}

Position		Key::direction(int id) const
{
	return _lastOkDir[id];
}