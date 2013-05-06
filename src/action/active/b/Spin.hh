//
// Spin.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 20 00:15:36 2013 Brunier Jean
// Last update Sat Apr 20 00:22:14 2013 Brunier Jean
//

#ifndef SPIN_HH_
# define SPIN_HH_

# include "AAction.hh"

class Spin : public AAction
{
public:
  Spin(Player &player);
  virtual ~Spin(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual void		upBones();
  virtual void		print(Graphics &g) const;
};

#endif /* !SPIN_HH_ */
