//
// HitWall.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 01:08:00 2013 Brunier Jean
// Last update Fri Apr 12 11:27:27 2013 Brunier Jean
//

#ifndef HITWALL_HH_
# define HITWALL_HH_

# include "AAction.hh"

class HitWall : public AAction
{
public:
  HitWall(Player &player);
  virtual ~Tech();
  virtual int		init();
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual void		check();
  virtual int		val();
};

#endif /* !HITWALL_HH_ */
