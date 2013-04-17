//
// DownDash.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 20:37:35 2013 Brunier Jean
// Last update Wed Apr 17 21:56:40 2013 Brunier Jean
//

#ifndef DOWNDASH_HH_
# define DOWNDASH_HH_

# include "AAction.hh"

class DownDash : public AAction
{
public:
  DownDash(Player &player);
  virtual ~DownDash(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual bool		request();
  virtual int		id();
  virtual void		upBones();
};

#endif /* !DOWNDASH_HH_ */
