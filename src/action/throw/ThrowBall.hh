//
// ThrowBall.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 23 03:11:46 2013 Brunier Jean
// Last update Tue Apr 23 03:20:10 2013 Brunier Jean
//

#ifndef THROWBALL_HH_
# define THROWBALL_HH_

# include "AAction.hh"

class ThrowBall : public AAction
{
public:
  ThrowBall(Player &player);
  virtual ~ThrowBall(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual void		set(int v = 0);
  virtual int		val();
  virtual bool		request();
  virtual void		upBones();
  virtual void		check();
  virtual void		print(Graphics &g) const;
};

#endif /* !THROWBALL_HH_ */
