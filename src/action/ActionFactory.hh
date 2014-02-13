//
// ActionFactory.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 13 10:33:21 2013 Brunier Jean
// Last update Sun Apr 14 17:40:38 2013 Brunier Jean
//

#ifndef ACTIONFACTORY_HH_
# define ACTIONFACTORY_HH_

class IAction;
class Player;

class ActionFactory
{
private:
	ActionFactory();
	ActionFactory(const ActionFactory &other);
	ActionFactory		&operator=(const ActionFactory &other);
	~ActionFactory();
public:
	static IAction	*get(int action, Player &p);
};

#endif /* !ACTIONFACTORY_HH_ */
