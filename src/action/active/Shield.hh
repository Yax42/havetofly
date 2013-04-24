//
// Shield.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 01:06:06 2013 Brunier Jean
// Last update Tue Apr 23 20:04:54 2013 Brunier Jean
//

#ifndef SHIELD_HH_
# define SHIELD_HH_

# include "AAction.hh"

class Shield : public AAction
{
public:
  Shield(Player &player);
  virtual ~Shield(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual void		set(int);
  virtual void		upBones();
  virtual void		check();
  virtual void		print(Graphics &g) const;
};

#endif /* !SHIELD_HH_ */
