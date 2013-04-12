//
// PassiveAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 11:35:39 2013 Brunier Jean
// Last update Fri Apr 12 11:40:11 2013 Brunier Jean
//

#ifndef PASSIVEACTION_HH_
# define PASSIVEACTION_HH_

# include "AAction.hh"

class PassiveAction : public AAction
{
public:
  PassiveAction(Player &player);
  virtual ~PassiveAction();
  virtual int		init();
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual void		check();
  virtual int		val();
};

#endif /* !PASSIVEACTION_HH_ */
