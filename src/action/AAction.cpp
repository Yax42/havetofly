//
// AAction.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 23:15:12 2013 Brunier Jean
// Last update Fri Apr 19 01:40:50 2013 Brunier Jean
//

# include "AAction.hh"
# include "Hit.hh"
# include "const.hh"

AAction::~AAction()
{
  if (_hit != NULL)
    delete (_hit);
}

AAction::AAction(Player &player, Hit *hit) :
	_player(player), _hit(hit), _open(1), _count(0), _bones(player.bones())
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

IAction		*AAction::step()
{
  _count--;
  if (_count != 0)
    return (this);
  return (_player[IAction::INERTIE]);
}

void	AAction::hit(Player &ennemy)
{
  if (_hit == NULL)
    return ;
  _hit->focus(ennemy);
}

int	AAction::val()
{
  return (_count);
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

void		AAction::print(Graphics &) const
{
}
