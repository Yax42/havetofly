//
// StickWall.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 16 21:05:53 2013 Brunier Jean
// Last update Sat Apr 27 23:27:19 2013 Brunier Jean
//

#include "StickWall.hh"

StickWall::StickWall(Player &player) : AAction(player, STICK_WALL, NULL)
{
}

bool	StickWall::allow(int a)
{
	return (a == WALL_JUMP || a == AUTO_GUN || a == THROW_SHURIKEN);
}

void	StickWall::init(int)
{
	UpdateOrient(_player(Event::LEFT_WALL) ? -1 : 1);
}

void	StickWall::step()
{
	if (_player.sy() < -3.3) // 2/3
		_player.sy(-3); // 2/3
	else if (_player.sy() <= 3.3) // 2/3
		_player.sy(_player.sy() + 0.0666); //2/3
	if (_player.sy() > 1)
		_player.sy(1);
		//_player.sy(_player.sy() + 0.066); //2/3
	/*
	if (_player(Event::RIGHT_WALL) && _player.key(Key::HOR) > 200)
		return (true);
		*/
	if ((!_player(Event::LEFT_WALL) || _player.key(Key::HOR) >= -200)
	&& (!_player(Event::RIGHT_WALL) || _player.key(Key::HOR) <= 200))
		_player.engageAction(INERTIE);
}

bool		StickWall::request()
{
	if (_player(Event::LEFT_WALL) && _player.key(Key::HOR) < -200)
		return (true);
	if (_player(Event::RIGHT_WALL) && _player.key(Key::HOR) > 200)
		return (true);
	return (false);
}

void		StickWall::upBones()
{
	_bones.angle[Bones::FOOT1] = Angle(-90, 0);
	_bones.angle[Bones::FOOT2] = Angle(-90, 0);
	_bones.angle[Bones::KNEE1] = Angle(80, 0);
	_bones.angle[Bones::KNEE2] = Angle(90, 0);

	_bones.angle[Bones::HAND1] = Angle(70, 0);
	_bones.angle[Bones::HAND2] = Angle(60, 0);
	_bones.angle[Bones::ELBOW1] = Angle(80, 0);
	_bones.angle[Bones::ELBOW2] = Angle(100, 0);

	_bones.angle[Bones::HEAD] = Angle(0, 0);
	_bones.angle[Bones::BODY] = Angle(0, 0);
}
