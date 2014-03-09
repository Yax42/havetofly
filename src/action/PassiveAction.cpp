//
// PassiveAction.cpp for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Fri Apr 12 11:40:32 2013 Brunier Jean
// Last update Fri Apr 19 18:13:09 2013 Brunier Jean
//

#include "PassiveAction.hh"

PassiveAction::PassiveAction(Player &player, int id) : AAction(player, id, NULL)
{
}

bool	PassiveAction::allow(int)
{
	return (true);
}

void	PassiveAction::step()
{
	_player.engageAction(INERTIE);
}

bool		PassiveAction::request()
{
	return (false);
}

void		PassiveAction::check()
{
}

int	PassiveAction::val()
{
	return (0);
}
void		PassiveAction::upBones()
{
}
