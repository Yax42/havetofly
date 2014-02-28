//
// Inertie.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Fri Apr 12 11:31:46 2013 Brunier Jean
// Last update Tue Apr 23 23:30:35 2013 Brunier Jean
//

#include "Inertie.hh"

Inertie::Inertie(Player &player) : PassiveAction(player, IAction::INERTIE)
{
}

bool				Inertie::request()
{
	static const float 	PSLOW = 0.01;
	static const float 	MSLOW = -0.01;

	if (_player.sx() <= PSLOW && _player.sx() >= MSLOW)
		_player.sx(0);
	else if (_player.sx() < MSLOW)
		_player.sx(_player.sx() + PSLOW);
	else
		_player.sx(_player.sx() + MSLOW);
	return (false);
}

void		Inertie::upBones()
{
	_bones.angle[Bones::FOOT1] = Angle(MGRAD_CAP(MTIME * 3, -80, 50), 0);
	_bones.angle[Bones::FOOT2] = Angle(MGRAD_CAP(MTIME * 4, -80, 50), 0);
	_bones.angle[Bones::KNEE1] = Angle(MGRAD_CAP(MTIME, -35, 30), 0);
	_bones.angle[Bones::KNEE2] = Angle(MGRAD_CAP(MTIME, -65, 30), 0);

	_bones.angle[Bones::HAND1] = Angle(MGRAD_CAP(MTIME * 3, 10, 50), 0);
	_bones.angle[Bones::ELBOW1] = Angle(MGRAD_CAP(MTIME, 195, 30), 0);
	_bones.angle[Bones::HAND2] = Angle(MGRAD_CAP(MTIME * 4, 10, 50), 0);
	_bones.angle[Bones::ELBOW2] = Angle(MGRAD_CAP(MTIME, 225, 30), 0);

	_bones.angle[Bones::HEAD] = Angle(-40, 0);
	_bones.angle[Bones::BODY] = Angle(-80, 0);
	_bones.angle[Bones::BODY] = Angle(60 - _player.sy() * 20 +
			MGRAD_CAP(MTIME / 4, -60, 20), 0);
	//std::cout << MGRAD_CAP(MTIME / 4, -60, 20) << std::endl;
}
