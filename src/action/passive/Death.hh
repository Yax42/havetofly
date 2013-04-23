//
// Death.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 19 23:17:20 2013 Brunier Jean
// Last update Mon Apr 22 14:42:33 2013 Brunier Jean
//

#ifndef DEATH_HH_
# define DEATH_HH_

# include "PassiveAction.hh"

class Death : public PassiveAction
{
public:
  Death(Player &player);
  virtual ~Death(){}
  virtual void		check();
};

#endif /* !DEATH_HH_ */
