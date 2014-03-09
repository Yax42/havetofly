//
// StickWall.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 16 21:05:48 2013 Brunier Jean
// Last update Fri Apr 19 13:55:55 2013 Brunier Jean
//

#ifndef STICKWALL_HH_
# define STICKWALL_HH_

# include "AAction.hh"

class StickWall : public AAction
{
public:
	StickWall(Player &player);
	virtual ~StickWall() {}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual void		step();
	virtual bool		request();
	virtual void		upBones();
};

#endif /* !STICKWALL_HH_ */
