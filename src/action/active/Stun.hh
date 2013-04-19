//
// Stun.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 23:22:45 2013 Brunier Jean
// Last update Fri Apr 19 13:56:33 2013 Brunier Jean
//

#ifndef STUN_HH_
# define STUN_HH_

# include "AAction.hh"

class Stun : public AAction
{
public:
  Stun(Player &player);
  virtual ~Stun(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual void		upBones();
  virtual void		set(int val = 0);
};


#endif /* !STUN_HH_ */
