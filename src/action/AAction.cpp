//
// AAction.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 23:15:12 2013 Brunier Jean
// Last update Sun May 05 23:34:32 2013 Brunier Jean
//

# include "AAction.hh"
# include "Hit.hh"
# include "const.hh"

AAction::~AAction()
{
	if (_hit != NULL)
		delete (_hit);
}

AAction::AAction(Player &player, int id, Hit *hit) :
	_player(player), _hit(hit), _open(1), _count(0), _bones(player.bones()), _id(id)
{
	loadBones();
}

void		AAction::loadBones()
{
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::FOOT1], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::FOOT2], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::HAND1], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::HAND2], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::ELBOW1], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::ELBOW2], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::KNEE1], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::KNEE2], _player.orient()));
	_hb.push_back(Hitbox(16, Position(), _bones[Bones::HEAD], _player.orient()));
	_hb.push_back(Hitbox(5, Position(), _bones[Bones::BODY], _player.orient()));
}

void		AAction::check()
{
}

void	AAction::init(int)
{
}

bool	AAction::allow(int)
{
	return (false);
}

void	AAction::step()
{
	_count--;
	if (_count != 0)
		_player.engageAction(IAction::INERTIE);
}

bool	AAction::hit(Player &ennemy)
{
	if (_hit == NULL)
		return (false);
	if (_hit->focus(ennemy))
		{
			if (ennemy.currentAction() != IAction::SHIELD)
				ennemy.hit(_hit);
			return (true);
		}
	return (false);
}

int	AAction::val()
{
	return (_count);
}

int		AAction::get(int)
{
	return 0;
}


const std::list<Hitbox>		&AAction::getHB() const
{
	return (_hb);
}

void		AAction::set(int)
{
	_open = 1;
}

void		AAction::printHB(Graphics &g) const
{
	for (std::list<Hitbox>::const_iterator i = _hb.begin(); i != _hb.end(); ++i)
		i->print(g, 0x0000FF);
	if (_hit != NULL)
		_hit->print(g);
}

bool		AAction::isActive() const
{
	return (_player.currentAction() == id());
}


int		AAction::id() const
{
	return (_id);
}

bool		AAction::request()
{
	return (false);
}

void		AAction::end()
{
}

void		AAction::print(Graphics &) const
{
	/*
	Angle		a = _player.closePos().angle();
 std::cout << (a.rad() % Math::maxRad) << " " << a.rad() << std::endl;
	g.circlePart(_bones[Bones::BODY], 60, a - (Angle(15, 0)), Angle(30, 0), 0xffffff);
	*/
}

void		AAction::upBones()
{
}

int		AAction::hitLagg() const
{
	if (_hit == NULL)
		return (0);
	return _hit->hitLagg();
}

void		AAction::tempo(int v) const
{
	_player.setAction(TEMPO, id());
	_player[TEMPO]->set(v);
}


Color		getColorFromLevel(int level)
{
	switch (level)
	{
		case 4:
			return Color(0, 0xCC, 0);
			break;
		case 3:
			return Color(0, 0, 0xCC);
			break;
		case 2:
			return Color(0x88, 0x88, 0);
			break;
		case 1:
			return Color(0xCC , 0, 0);
			break;
	};
	return Color::BLACK;
}