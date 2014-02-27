//
// HitWall.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 11 01:08:00 2013 Brunier Jean
// Last update Fri Apr 19 13:57:22 2013 Brunier Jean
//

#ifndef HITWALL_HH_
# define HITWALL_HH_

# include "PassiveAction.hh"

class HitWall : public PassiveAction
{
public:
	HitWall(Player &player);
	virtual ~HitWall() {}
	virtual void		check();
	virtual int			val();
private:
	int				_lastWallHit;
	int				_newLastWallHit;
};

#endif /* !HITWALL_HH_ */
