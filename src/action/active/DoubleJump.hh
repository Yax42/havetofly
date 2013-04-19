//
// DoubleJump.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 21:03:08 2013 Brunier Jean
// Last update Fri Apr 19 01:37:42 2013 Brunier Jean
//

#ifndef DOUBLEJUMP_HH_
# define DOUBLEJUMP_HH_

# include "AAction.hh"

class DoubleJump : public AAction
{
public:
  DoubleJump(Player &player);
  virtual ~DoubleJump(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual int		id();
  virtual void		upBones();
  virtual void		check();
  virtual void		print(Graphics &g) const;
};

#endif /* !DOUBLEJUMP_HH_ */
