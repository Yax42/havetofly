//
// DownDash.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 20:38:01 2013 Brunier Jean
// Last update Mon May 06 22:33:21 2013 Brunier Jean
//

#include "DownDash.hh"

DownDash::DownDash(Player &player) :
	AAction(player, DOWN_DASH, new Hit(60, Position(3, 3), player.orient(), 15, false, Hit::ORIENT))
{
	_number = 0;
	_hit->add(15, Position(), _bones[Bones::FOOT1]);
	_hit->add(15, Position(), _bones[Bones::FOOT2]);
}

void	DownDash::init(int v)
{
	if (v == 0 && !PLANE_DEBUG)
	{
		_number += (_number < 5);
		tempo(_number * _number);
	}
	else
	{
		_player[UP_PUNCH]->set();
		_player[AUTO_GUN]->set(4);
		_player = Position(5, _player.orient() * 4);
		_hit->reset();
		_count = 30;
	}
}

bool	DownDash::allow(int)
{
	return (false);
}

void	DownDash::step()
{
	if (--_count == 0)
	{
		_player = Position(-3, _player.orient() * -5);
		//_player[IAction::DOUBLE_JUMP]->set();
		_player.engageAction(INERTIE);
	}
	else if ((_player(Event::LEFT_WALL) && _player.orient() < 0) ||
			(_player(Event::RIGHT_WALL) && _player.orient() > 0))
	{
		_player.engageAction(WALL_JUMP, -3);
	}
	else
	{
		if (_player(Event::DID_HIT))
			_count = 10;
		_player = Position(5, _player.orient() * 4);
	}
}

void		DownDash::check()
{
	if (_player.pos().y > MAP_H - 40)
		_number = 0;
}

bool		DownDash::request()
{
	return (_player.key[Key::Y] == 1 && !_player.key(Key::R) && _player.key[Key::VERT] == 1);
}

int			DownDash::val()
{
	return _number;
}

void		DownDash::upBones()
{
	_bones.angle[Bones::FOOT1] = Angle(10, 0);
	_bones.angle[Bones::FOOT2] = Angle(-5, 0);
	_bones.angle[Bones::KNEE1] = Angle(10, 0);
	_bones.angle[Bones::KNEE2] = Angle(5, 0);

	_bones.angle[Bones::HAND1] = Angle(-70, 0);
	_bones.angle[Bones::HAND2] = Angle(60, 0);
	_bones.angle[Bones::ELBOW1] = Angle(80, 0);
	_bones.angle[Bones::ELBOW2] = Angle(-100, 0);

	_bones.angle[Bones::HEAD] = Angle(0, 0);
	_bones.angle[Bones::BODY] = Angle(30, 0);
}

void		DownDash::print(Graphics &g) const
{
	g.line(Position(MAP_H - 40, 0), Position(MAP_H - 40, MAP_W), 0xFFFFFF, 5);
}