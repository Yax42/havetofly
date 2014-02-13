//
// Inertie.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Fri Apr 12 11:20:17 2013 Brunier Jean
// Last update Fri Apr 19 13:57:37 2013 Brunier Jean
//

#ifndef INERTIE_HH_
# define INERTIE_HH_

# include "PassiveAction.hh"

class Inertie : public PassiveAction
{
public:
	virtual ~Inertie(){}
	Inertie(Player &player);
	virtual void		upBones();
	virtual bool		request();
};

#endif /* !INERTIE_HH_ */
