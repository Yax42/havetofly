//
// StickCeiling.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 16 20:10:54 2013 Brunier Jean
// Last update Fri Apr 19 13:55:40 2013 Brunier Jean
//

#ifndef STICKCEILING_HH_
# define STICKCEILING_HH_

# include "AAction.hh"

class StickCeiling : public AAction
{
public:
	StickCeiling(Player &player);
	virtual ~StickCeiling() {}
	virtual void		init(int v = 0);
	virtual void		step();
	virtual bool		request();
	virtual void		upBones();
};

#endif /* !STICKCEILING_HH_ */
