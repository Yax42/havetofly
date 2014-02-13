//
// WallJump.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 16 21:44:15 2013 Brunier Jean
// Last update Fri Apr 19 13:56:47 2013 Brunier Jean
//

#ifndef WALLJUMP_HH_
# define WALLJUMP_HH_

# include "AAction.hh"

class WallJump : public AAction
{
public:
	WallJump(Player &player);
	virtual ~WallJump(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual IAction	*step();
	virtual bool		request();
	virtual void		upBones();
};


#endif /* !WALLJUMP_HH_ */
