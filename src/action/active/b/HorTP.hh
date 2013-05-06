//
// HorTP.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun May 05 18:44:20 2013 Brunier Jean
// Last update Sun May 05 18:59:44 2013 Brunier Jean
//

#ifndef HORTP_HH_
# define HORTP_HH_

# include "AAction.hh"

class HorTP : public AAction
{
protected:
  int		_sign;
public:
  HorTP(Player &player);
  virtual ~HorTP(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual void		set(int);
  virtual bool		request();
  virtual void		upBones();
  virtual void		check();
  virtual void		print(Graphics &g) const;
};

#endif /* !HORTP_HH_ */
