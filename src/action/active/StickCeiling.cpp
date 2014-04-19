//
// StickCeiling.cpp for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 16 20:10:47 2013 Brunier Jean
// Last update Sat Apr 20 18:12:54 2013 Brunier Jean
//

#include "StickCeiling.hh"
#include "Game.hh"

StickCeiling::StickCeiling(Player &player) : AAction(player, STICK_CEILING, NULL)
{
}

void	StickCeiling::init(int)
{
	_player = Position();
}

void	StickCeiling::step()
{	
//	_player[IAction::INERTIE]->request();
//	_player[IAction::MOVE]->request();
	if (_player.key[Key::HOR] < 0)
		_player.orient(-1);
	else if (_player.key[Key::HOR] > 0)
		_player.orient(1);
	if (_player.key(Key::VERT) >= 0 || !Game::isCeilingOn())
		_player.engageAction(INERTIE);
}

bool		StickCeiling::request()
{
	return (_player(Event::CEILING) && _player.key[Key::VERT] < 0);
}

void		StickCeiling::upBones()
{
	Bones		&bones = _player.bones();

	bones.angle[Bones::FOOT1] = Angle(90, 0);
	bones.angle[Bones::FOOT2] = Angle(90, 0);
	bones.angle[Bones::KNEE1] = Angle(-80, 0);
	bones.angle[Bones::KNEE2] = Angle(-90, 0);

	bones.angle[Bones::HAND1] = Angle(-70, 0);
	bones.angle[Bones::HAND2] = Angle(-60, 0);
	bones.angle[Bones::ELBOW1] = Angle(-80, 0);
	bones.angle[Bones::ELBOW2] = Angle(-100, 0);

	bones.angle[Bones::HEAD] = Angle(0, 0);
	bones.angle[Bones::BODY] = Angle(-90, 0);
}
