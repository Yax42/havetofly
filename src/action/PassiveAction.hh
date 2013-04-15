//
// PassiveAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 11:35:39 2013 Brunier Jean
// Last update Sun Apr 14 17:56:07 2013 Brunier Jean
//

#ifndef PASSIVEACTION_HH_
# define PASSIVEACTION_HH_

# include "AAction.hh"

class PassiveAction : public AAction
{
public:
  PassiveAction(Player &player);
  virtual ~PassiveAction(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual void		check();
  virtual int		val();
  virtual void		upBones();
  virtual int		id() = 0;
};

#endif /* !PASSIVEACTION_HH_ */
