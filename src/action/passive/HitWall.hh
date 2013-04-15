//
// HitWall.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 01:08:00 2013 Brunier Jean
// Last update Sun Apr 14 17:22:38 2013 Brunier Jean
//

#ifndef HITWALL_HH_
# define HITWALL_HH_

# include "PassiveAction.hh"

class HitWall : public PassiveAction
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
