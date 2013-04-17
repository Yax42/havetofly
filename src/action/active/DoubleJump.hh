//
// DoubleJump.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 21:03:08 2013 Brunier Jean
// Last update Wed Apr 17 21:19:28 2013 Brunier Jean
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
};

#endif /* !DOUBLEJUMP_HH_ */
