//
// DeathRay.hh for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun May 05 13:56:39 2013 Brunier Jean
// Last update Sun May 05 16:20:29 2013 Brunier Jean
//

#ifndef DEATHRAY_HH_
# define DEATHRAY_HH_

# include "AThrowable.hh"

class DeathRay : public AThrowable
{
private:
	Player		*_player;
	int			steps;
public:
	virtual ~DeathRay(){}
	DeathRay(Player &player, const Angle &a);
	virtual void		move();
	virtual void		effect(Player &p);
	virtual void		print(Graphics &g) const;
};

#endif /* !DEATHRAY_HH_ */
