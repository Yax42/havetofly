//
// HorDash.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 18 23:26:51 2013 Brunier Jean
// Last update Fri Apr 19 13:55:10 2013 Brunier Jean
//

#ifndef HORDASH_HH_
# define HORDASH_HH_

# include "AAction.hh"

class HorDash : public AAction
{
public:
  HorDash(Player &player);
  virtual ~HorDash(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual void		upBones();
  virtual void		check();
  virtual void		print(Graphics &g) const;
};

#endif /* !HORDASH_HH_ */