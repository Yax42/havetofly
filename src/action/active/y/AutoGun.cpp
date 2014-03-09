//
// AutoGun.cpp for throw in /home/brunie_j/local/my/havetofly/src/action/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 27 22:41:50 2013 Brunier Jean
// Last update Sun May 05 13:52:53 2013 Brunier Jean
//

#include "AutoGun.hh"
#include "Blast.hh"
#define RELOADING	30

AutoGun::AutoGun(Player &player) : AAction(player, THROW_BALL, NULL)
{
	_open = 16;
}

void	AutoGun::init(int)
{
	_player = Position();
	_count = 250;
	_angle = ((_player.orient() == 1) ? Angle(180, 0) : Angle(0, 0));
	if (_player.key[Key::VERT])
		_sign = _player.key[Key::VERT] * -_player.orient();
	else
		_sign = _player.orient();
}

bool	AutoGun::allow(int a)
{
	return (a == WALL_JUMP);
}

void	AutoGun::step()
{
	if (_player.key[Key::VERT])
		_sign = _player.key[Key::VERT] * -_player.orient();
	_angle += Angle(_sign * 0.3);
	if(_count > RELOADING && _count < 200)
	{
		if (_count % 10 == 0 && _open)
		{
			_player.doThrow(new Blast(_player, _angle));
			_open--;
		}
	}
	if (_count-- == 0 || _open == 0 || (!_player.key(Key::Y) && _count <= 189))
		_player.engageAction(INERTIE);
}

bool		AutoGun::request()
{
	return (_player[STICK_WALL]->isActive() && _player.key[Key::Y] && _open);
}

void		AutoGun::upBones()
{
	/*
	_bones.angle[Bones::FOOT1] = Angle(90, 0);
	_bones.angle[Bones::KNEE1] = Angle(0, 0);
	_bones.angle[Bones::HAND1] = Angle(-90, 0);
	_bones.angle[Bones::ELBOW1] = Angle(180, 0);

	_bones.angle[Bones::FOOT2] = ((_player.orient() == 1) ?
			_angle.mirrorX() - Angle(90, 0) :
			_angle + Angle(90, 0));

	_bones.angle[Bones::KNEE2] = Angle(180, 0);
	_bones.angle[Bones::HAND2] = Angle(90, 0);
	_bones.angle[Bones::ELBOW2] = Angle(0, 0);

	_bones.angle[Bones::HEAD] = Angle(-90, 0);
	_bones.angle[Bones::BODY] = Angle(0, 0);
			*/
	_bones.angle[Bones::FOOT1] = Angle(-70, 0);
	_bones.angle[Bones::FOOT2] = Angle(0, 0);
	_bones.angle[Bones::KNEE1] = Angle(70, 0);
	_bones.angle[Bones::KNEE2] = Angle(0, 0);

	_bones.angle[Bones::HAND1] = Angle(70, 0);
	_bones.angle[Bones::HAND2] = Angle(70, 0);
	_bones.angle[Bones::ELBOW1] = Angle(-90, 0);
	_bones.angle[Bones::ELBOW2] = Angle(-90, 0);

	_bones.angle[Bones::HEAD] = Angle(0, 0);
	_bones.angle[Bones::BODY] = ((_player.orient() == 1) ?
			_angle.mirrorX() + Angle(90, 0) :
			_angle - Angle(90, 0));
}

void		AutoGun::check()
{
}

void		AutoGun::set(int v)
{
	_open += v;
	if (_open > 16)
		_open = 16;
	else if (_open < 0)
		_open = 0;
}

int		AutoGun::val()
{
	return (_open);
}

void		AutoGun::print(Graphics &g) const
{
	int		val;

	if (isActive() && _count < 200 && _open)
		{
			for (int i = 0; i < 10; i++)
				{
		val = (rand() % (200 - _count + 2)) * 2;
		g.circlePart(_bones[Bones::FOOT2] - Position(_angle + Angle(180, 0), val), val,
				_angle + Angle(140, 0), Angle(80, 0), Color::fire[rand() % 4]);
		g.line(_bones[Bones::FOOT2], _bones[Bones::FOOT2] - Position(_angle + Angle(180, 0), val) + MRAND_POS_CI(30), Color::fire[rand() % 4]);
	}
		}
	if (_open > 3)
		g.line(_bones[Bones::FOOT2], _bones[Bones::KNEE2], 0xFFffFF, 4);
	if (_open > 7)
		g.line(_bones[Bones::KNEE2], _bones[Bones::BODY], 0xFFffFF, 4);
	if (_open > 11)
		g.line(_bones[Bones::KNEE1], _bones[Bones::BODY], 0xFFffFF, 4);
	if (_open > 15)
		g.line(_bones[Bones::FOOT1], _bones[Bones::KNEE1], 0xFFffFF, 4);
}
