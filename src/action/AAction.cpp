//
// AAction.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 23:15:12 2013 Brunier Jean
// Last update Thu Apr 18 13:09:49 2013 Brunier Jean
//

# include "AAction.hh"
# include "Hit.hh"
# include "const.hh"

AAction::~AAction()
{
  if (_hit != NULL)
    delete (_hit);
}

AAction::AAction(Player &player, Hit *hit) : _player(player), _hit(hit), _open(1), _count(0),
  _hb(32, Position(0, 0), player.pos(), player.orient())
{
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

const Hitbox	&AAction::getHB() const
{
  return (_hb);
}

void		AAction::set(int)
{
  _open = 1;
}

void		AAction::printHB(Graphics &g) const
{
  _hb.print(g, 0x0000FF);
  if (_hit != NULL)
    _hit->print(g);
}

void		AAction::print(Graphics &, const Bones &) const
{
}
