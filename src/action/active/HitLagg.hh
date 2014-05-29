//
// HitLagg.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Mon Apr 22 14:42:03 2013 Brunier Jean
// Last update Mon Apr 22 15:26:44 2013 Brunier Jean
//

#ifndef HITLAGG_HH_
# define HITLAGG_HH_

# include "PassiveAction.hh"

class HitLagg : public PassiveAction
{
public:
	HitLagg(Player &player);
	virtual ~HitLagg(){}
	virtual void		init(int v);
	virtual int			val();
	virtual void		check();
	virtual void		step();
};

#endif /* !HITLAGG_HH_ */
