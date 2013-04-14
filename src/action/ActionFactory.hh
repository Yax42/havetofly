//
// ActionFactory.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 10:33:21 2013 Brunier Jean
// Last update Sat Apr 13 20:49:27 2013 Brunier Jean
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
  static IAction	*get(int action, Player const &p);
};

#endif /* !ACTIONFACTORY_HH_ */
