//
// Chain.hh for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 19 11:09:09 2014 Brunier Jean
// Last update Tue Apr 19 20:11:50 2014 Brunier Jean
//

#ifndef CHAIN_HH_
# define CHAIN_HH_

# include "AThrowable.hh"

class Chain : public AThrowable
{
private:
	bool	_didGrab;
	bool	_grabbedHuman;
	int		_life;
	Player	*_victim;
public:
	virtual ~Chain(){}
	Chain(Player &player, const Position &speed);
	virtual void		move();
	virtual void		print(Graphics &g) const;
	virtual void		effect(Player &p);
	virtual void		effectWall();
};

#endif /* !CHAIN_HH_ */