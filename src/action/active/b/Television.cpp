//
// Television.cpp for b in /home/brunie_j/local/my/havetofly/src/action/active/b
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun May 05 19:28:37 2013 Brunier Jean
// Last update Tue May 07 11:08:31 2013 Brunier Jean
//

#include "Television.hh"
#include "EffectiveTV.hh"

const int Television::size = 80;

Television::Television(Player &player) : AAction(player, TELEVISION,
		new Hit(0, Position(), player.orient(), 0, false, Hit::ORIENT))
{
	_hit->add(size / 2, Position(size / 2 - 30, player.orient() * (30 + size / 2)), player.pos());
}

void	Television::init(int)
{
	_player[SHIELD]->set();
	_hit->reset();
	_patern.clear();
	_didHit = false;
	_count = 90;
	if (_player.key(Key::HOR) < 0)
		_player.orient(-1);
	else if (_player.key(Key::HOR) > 0)
		_player.orient(1);
	_player = Position();
}

bool	Television::allow(int)
{
	return (false);
}

void	Television::step()
{
	if (_count != 90 && _count > 15 && _player.key.cur() &&
		(_patern.size() == 0 ||
		_player.key.cur() != _patern.back()))
		_patern.push_back(_player.key.cur());
	if (_count--)
		return ;
	if (_didHit)
	{
		reinterpret_cast<EffectiveTV *>
			(_player[EFFECTIVE_TV])->setPatern(_patern);
		_player.engageAction(EFFECTIVE_TV);
	}
	else
		_player.engageAction(INERTIE);
}

bool		Television::request()
{
	return (_player.key[Key::B] == 1 &&
			_player.key[Key::HOR] &&
			_player[SHIELD]->val());
}

bool	Television::hit(Player &ennemy)
{
	if (_hit->focus(ennemy))
		{
			_didHit = true;
			ennemy.setAction(EFFECTIVE_TV, _count);
			reinterpret_cast<EffectiveTV *> (ennemy[EFFECTIVE_TV])->setPatern(_patern);
		}
	return (false);
}

void		Television::check()
{
}

void		Television::set(int)
{
}

int		Television::val()
{
	return (_count);
}

/************/
/* GRAPHICS */
/************/
void		Television::upBones()
{
	_bones.angle[Bones::FOOT1] = Angle(0, 0);
	_bones.angle[Bones::FOOT2] = Angle(0, 0);
	_bones.angle[Bones::KNEE1] = Angle(90, 0);
	_bones.angle[Bones::KNEE2] = Angle(80, 0);

	_bones.angle[Bones::HAND1] = Angle(0, 0);
	_bones.angle[Bones::HAND2] = Angle(0, 0);
	_bones.angle[Bones::ELBOW1] = Angle(90, 0);
	_bones.angle[Bones::ELBOW2] = Angle(80, 0);

	_bones.angle[Bones::HEAD] = Angle(0, 0);
	_bones.angle[Bones::BODY] = Angle(0, 0);
}

void		Television::print(Graphics &g) const
{
	if (isActive())
		{
			Position		pos1 = _player.pos() +
	Position(-30, (_player.orient() == -1 ? -30 - size : 30));
			Position		pos2 = pos1 + Position(size, size);

			g.rectangleLaid(pos1, pos2, Color::WHITE, Color::BLACK);
			/*g.circlePart((pos1 + pos2) / 2, Math::sqrt((size * size) / 2) /
			 Distance(2), Angle(_count * 4, 0), Angle(30, 0), Color::BLACK);
			*/
			if (_patern.size() != 0)
				{
		bool		choice = (rand() % 2 == 0);
		Color		col1 = (choice ? Color::WHITE : Color::BLACK);
		//Color		col2 = (choice ? Color::BLACK : Color::WHITE);

		if (_patern.back() == Key::A)
		{
				g.circleLaid(pos1 + Position(size / 2 + 20, size / 2), 10, col1, col1);
				g.circleFull(pos1 + Position(size / 2 + 20, size / 2), 7, Color::GREEN);
		}
		else if (_patern.back() == Key::X)
		{
				g.circleLaid(pos1 + Position(size / 2, size / 2 - 20), 10, col1, col1);
				g.circleFull(pos1 + Position(size / 2, size / 2 - 20), 7, Color::BLUE);
		}
		else if (_patern.back() == Key::Y)
		{
				g.circleLaid(pos1 + Position(size / 2 - 20, size / 2), 10, col1, col1);
				g.circleFull(pos1 + Position(size / 2 - 20, size / 2), 7, Color::YELLOW);
		}
		else if (_patern.back() == Key::B)
		{
				g.circleLaid(pos1 + Position(size / 2, size / 2 + 20), 10, col1, col1);
				g.circleFull(pos1 + Position(size / 2, size / 2 + 20), 7, Color::RED);
		}
	}
		}
}
