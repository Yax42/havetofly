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
#include "Game.hh"

DownDash::DownDash(Player &player) :
	AAction(player, DOWN_DASH, new Hit(50, Position(3, 3), player.orient(), 15, false, Hit::ORIENT))
{
	_hit->add(15, Position(), _bones[Bones::FOOT1]);
	_hit->add(15, Position(), _bones[Bones::FOOT2]);
}

void	DownDash::init(int v)
{
	UpdateOrient(_player.key(Key::HOR));
	_hit->reset();
	_hit->sleep(true);
	_count = 45;
	_player = Position();
	_graphicAngle = Angle(30, 0);
	_isCanceled = false;
}

bool	DownDash::allow(int)
{
	return (false);
}


/*
bool		DownDash::checkShurikenCancel()
{
	if (!_player.key(Key::Y) && !_prevWasCancelAndNotWalled)
	{
		_prevWasCancelAndNotWalled = true;
		float	next = (float(_player.y()) / float(Game::h()));
		next *= 5;
		if (_shurikenCancel < next)
		{
			_shurikenCancel = next;
			return true;
		}
	}
	else
	{
		_prevWasCancelAndNotWalled = false;
		return false;
	}
}
*/

void			DownDash::updateSpeed()
{

	Position	factors;
	if (!_isCanceled)
		factors = Position (7, 7);
	else if (_count > 15)
		factors = Position (2, 6);
	else
		factors = Position (6, 1);

	_player = Position(factors.y, _player.orient() * factors.x);
		/*
		float	factor = 1.0f - _count / 30.0;
		factor = 1.f - factor * factor * factor;
		_player = Position(9 - 9 * factor, _player.orient() * (4 + factor * 2));
		*/

	_graphicAngle = (_player.speed().angle().rad() - Math::PiHalf) * (-_player.orient());
}

void	DownDash::step()
{
	_count--;
	if (_count > 30)
	{
	}
	else if (_count == 30)
	{
		_heightFactor = float(_player.y()) / float(Game::h());

		//if (_player.key.getKey(Key::Y) != 1 && _player.pos().y > Game::h() / 2)
			//_isCanceled = true;
		//else
			_hit->sleep(false);
	}
	else if ((_count == 0 && !_isCanceled) || (_isCanceled && _count == -15))
	{
		_player.sx(_player.sx() / 2);
		//_player.sy(_player.sy() / 2);
		_player.engageAction(INERTIE);
	}
	else if ((_player(Event::LEFT_WALL) && _player.orient() < 0) ||
			(_player(Event::RIGHT_WALL) && _player.orient() > 0))
	{
		if (_player.pos().y > Game::h() / 2)
			_player.engageAction(WALL_JUMP, -5);
		else
			_player.engageAction(WALL_JUMP, -3);
	}
	else
	{
		updateSpeed();
	}
}

void		DownDash::check()
{
}

bool		DownDash::request()
{
	return (_player.key[Key::Y] == 1 && !_player.key(Key::R2) && _player.key[Key::VERT] == 1);
}

int			DownDash::val()
{
	return 0;
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
	_bones.angle[Bones::BODY] = _graphicAngle;//Angle(30, 0);
}

void		DownDash::print(Graphics &g) const
{
}