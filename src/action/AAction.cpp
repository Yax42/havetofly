//
// AAction.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 23:15:12 2013 Brunier Jean
// Last update Tue Apr 16 20:37:43 2013 Brunier Jean
//

# include "AAction.hh"
# include "Hit.hh"

AAction::AAction(Player &player, Hit *hit) : _player(player), _hit(hit), _open(1), _count(0),
  _hb(Position(32, 32), Position(32, 32), player.pos())
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

