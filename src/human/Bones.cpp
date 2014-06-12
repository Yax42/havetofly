//
// Bones.cpp for human in /home/diallo_e/tmp/havetofly/src/human
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 17:23:55 2013 Brunier Jean
// Last update Wed Apr 24 17:01:26 2013 aliou diallo
//

#include "Bones.hh"
#include "Graphics.hh"
#include "Circle.hh"
#include "Math.hh"
#include "Player.hh"

#include <iostream>

const int	Bones::Size[Bones::COUNT] =
{
	24,	// FOOT1
	24,	// KNEE1
	20,	// HAND1
	14,	// ELBOW1
	24,	// FOOT2
	24,	// KNEE2
	20,	// HAND2
	14,	// ELBOW2
	14,	// HEAD
	18	// BODY
};

Bones::Bones(Player &player, int color2) :
	_player(player), _color2(color2)
{
	(void) _color2;
}

Bones::~Bones()
{
}

void		Bones::print(Graphics &g)
{
	Position	center = _player.pos();
	Position	avg;
	check();

	_pos[BODY] =	Position(_angle[BODY], Size[BODY]);
	_pos[HEAD] =	Position(_angle[HEAD] + _angle[BODY] + Angle(180, 0), Size[HEAD]);
	for (int i = 0; i < 4; i++)
	{
		_pos[i * 2 + 1] = ((i % 2) ? Position() : _pos[BODY]) +
			Position(_angle[i * 2 + 1] +
			_angle[BODY], Size[i * 2 + 1]);
		_pos[i * 2] = _pos[i * 2 + 1] + Position(_angle[i * 2] +
			_angle[BODY] + _angle[i * 2 + 1], Size[i * 2]);
	}

	/*
	for (int i = 0; i < Bones::HEAD; i++)
		avg += _pos[i];
	center += avg / 4;
	*/
	for (int i = 0; i < Bones::COUNT; i++)
		_pos[i] += center;

	int		tech = _player[IAction::TECH]->get(0);
	Color	color = tech > 70 ? Color::WHITE : (tech < 40 && tech > 20) ? Color::BLACK : _player.color();

	if (!_player[IAction::HOR_DASH]->val())
	{
		for (int i = 0; i < 3; i++)
			g.circle(_pos[HEAD], Size[HEAD] - i, color);
	}

	g.line(center, _pos[BODY], color, 6);
	for (int i = 0; i < 4; i++)
	{
		g.line(((i % 2) ? center : _pos[BODY]), _pos[i * 2 + 1], color, 6);
		g.line(_pos[i * 2 + 1], _pos[i * 2], color, 6);
	}
}

void	Bones::check()
{
	if (_player.orient() > 0)
		for (int i = 0; i < Bones::COUNT; i++)
			_angle[i] = angle[i].mirrorX();
	else
		for (int i = 0; i < Bones::COUNT; i++)
			_angle[i] = angle[i];
	_angle[BODY] += Angle(90, 0);
}

const Position		&Bones::operator[](int id) const
{
	return (_pos[id]);
}

void			Bones::set(float knee1, float foot1, float knee2, float foot2,
						float elbow1, float hand1, float elbow2, float hand2,
						float head, float body)
{
	angle[BODY] = Angle(body, 0);
	angle[HEAD] = Angle(head, 0);
	angle[ELBOW2] = Angle(elbow2, 0);
	angle[HAND2] = Angle(hand2, 0);
	angle[KNEE2] = Angle(knee2, 0);
	angle[FOOT2] = Angle(foot2, 0);
	angle[ELBOW1] = Angle(elbow1, 0);
	angle[HAND1] = Angle(hand1, 0);
	angle[KNEE1] = Angle(knee1, 0);
	angle[FOOT1] = Angle(foot1, 0);
}