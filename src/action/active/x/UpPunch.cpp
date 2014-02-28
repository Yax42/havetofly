//
// UpPunch.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 20 19:47:34 2013 Brunier Jean
// Last update Mon May 06 22:34:03 2013 Brunier Jean
//

#include "UpPunch.hh"

UpPunch::UpPunch(Player &player) : AAction(player, UP_PUNCH,
		new Hit(130, Position(-2.5, 2), player.orient(), 20, false, Hit::ORIENT))
{
	_hit->add(25, Position(-10, 0), _bones[Bones::HAND1]);
	_open = 1;
}

void		UpPunch::loadBones()
{
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::FOOT1], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::FOOT2], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::HAND2], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::ELBOW2], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::KNEE1], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::KNEE2], _player.orient()));
	_hb.push_back(Hitbox(16, Position(), _bones[Bones::HEAD], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::BODY], _player.orient()));
}

void	UpPunch::init(int v)
{
	if (v == 0 && !PLANE_DEBUG)
	{
		tempo(12);
	}
	else
	{
		_open = 0;
		_hit->reset();
		_count = 50;
		_player.sy(-3);
		_player.sx(_player.orient());
	}
}

void	UpPunch::set(int)
{
	_open = 1;
}

int	UpPunch::val()
{
	return (_open);
}

bool	UpPunch::allow(int)
{
	return (PLANE_DEBUG);
}

IAction		*UpPunch::step()
{
	/*
	if (_player(Event::CEILING))
	{
		_player[IAction::DOUBLE_JUMP]->set(0);
		_count = 0;
	}
	*/
	if (_count-- == 0)
	{
		_player.sy(-1);
		return (_player[INERTIE]);
	}
	return (this);
}

bool		UpPunch::request()
{
	return (_open && _player.key[Key::Y] == 1 &&
	_player.key[Key::VERT] == -1);
}

void		UpPunch::upBones()
{
	_bones.angle[Bones::FOOT1] = Angle(-20, 0);
	_bones.angle[Bones::FOOT2] = Angle(-40, 0);
	_bones.angle[Bones::KNEE1] = Angle(10, 0);
	_bones.angle[Bones::KNEE2] = Angle(-10, 0);

	_bones.angle[Bones::HAND1] = Angle(45, 0);
	_bones.angle[Bones::HAND2] = Angle(-20, 0);
	_bones.angle[Bones::ELBOW1] = Angle(130, 0);
	_bones.angle[Bones::ELBOW2] = Angle(-30, 0);

	_bones.angle[Bones::HEAD] = Angle(60, 0);
	_bones.angle[Bones::BODY] = Angle(MTIME * 0, 0);
}

void		UpPunch::check()
{
}

void		UpPunch::print(Graphics &g) const
{
	static const int	size = 25;
	if (isActive())
	{
		//g.line(Position(Distance(313539, 0), Distance(308258, 0)), Position(Distance(326746, 0), Distance(292605, 0)), 0);
		/*
		for (int i = 0; i < 350; i++)
		g.line(_bones[Bones::HAND1] + MRAND_POS(20) - Position(30, 0), _bones[Bones::HAND1] + MRAND_POS(size), 0);
		*/
		for (int i = 0; i < 70; i++)
			g.line(_bones[Bones::HAND1] + Position(-30, 0) + MRAND_POS_CI(10),
				_bones[Bones::HAND1] + Position (20, 0) +
				MRAND_POS_CI(size), Color::fire[rand() % 4]);
	}
	else if (_open == 1)
	{
		/*
		for (int i = 0; i < 50; i++)
		g.line(_bones[Bones::HAND1], _bones[Bones::HAND1] + MRAND_POS_CI(8), color[rand() % 4]);
		g.circleLaid(_bones[Bones::HAND1], 8, color[0], color[2]);
		//g.circleLaid(_bones[Bones::HAND1], 6, color[0], color[2]);
		g.circleLaid(_bones[Bones::HAND1], 2, color[0], color[2]);
		g.circlePart(_bones[Bones::HAND1], 4, Angle(MTIME * 4 - 15, 0), Angle(110, 0), color[0]);
		g.circlePart(_bones[Bones::HAND1], 5, Angle(MTIME * 4, 0), Angle(110, 0), color[3]);
		g.circlePart(_bones[Bones::HAND1], 6, Angle(MTIME * 4 + 15, 0), Angle(110, 0), color[0]);
		*/
		//			g.circleLaid(_bones[Bones::HAND1], 5, color[0], color[2]);
		/*
		*/
		for (int i = 0; i < 7; i++)
			g.circle(_bones[Bones::HAND1], (MTIME / 5 + i) % (12 - _player[DOWN_DASH]->val()) + 1, Color::fire[(i) % 4]);
	}
}
