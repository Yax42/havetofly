//
// DoubleJump.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 21:03:08 2013 Brunier Jean
// Last update Thu Apr 11 00:02:53 2013 Brunier Jean
//

#ifndef DOUBLEJUMP_HH_
# define DOUBLEJUMP_HH_

# include "AAction.hh"

class DoubleJump : public AAction
{
public:
  DoubleJump(Player &player);
  virtual ~DoubleJump();
  virtual int		init();
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual void		check();
};

#endif /* !DOUBLEJUMP_HH_ */
