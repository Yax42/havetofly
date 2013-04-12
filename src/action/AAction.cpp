//
// AAction.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 23:15:12 2013 Brunier Jean
// Last update Fri Apr 12 11:21:43 2013 Brunier Jean
//

# include "AAction.hh"
# include "Hit.hh"

AAction::AAction(Player &player, Hit *hit) : _player(player), _hit(hitA), _busy(0), _count(0)
{
}

AAction::~AAction()
{
}

int	AAction::init()
{
}

bool	AAction::allow(int a)
{
  return (false);
}

IAction		*AAction::step()
{
  _count--;
  if (_count != 0)
    return (this);
  return (NULL);
}

void	AAction::hit(Player &ennemy)
{
  if (_hit == NULL)
    return ;
  hit->focus(ennemy);
}

int	AAction::val()
{
  return (_count);
}
