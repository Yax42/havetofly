//
// Shuriken.hh for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 23 11:09:09 2013 Brunier Jean
// Last update Tue Apr 23 20:11:50 2013 Brunier Jean
//

#ifndef SHURIKEN_HH_
# define SHURIKEN_HH_

# include "AThrowable.hh"

class Shuriken : public AThrowable
{
private:
	int					_level;
public:
	virtual ~Shuriken(){}
	Shuriken(Player &player, const Position &pos, const Position &speed, int level);
	virtual void		move();
	virtual void		print(Graphics &g) const;
	virtual void		effect(Player &p);
};

#endif /* !SHURIKEN_HH_ */
