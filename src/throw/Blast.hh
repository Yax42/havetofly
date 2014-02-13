//
// Blast.hh for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 27 22:48:02 2013 Brunier Jean
// Last update Sat Apr 27 22:48:49 2013 Brunier Jean
//

#ifndef BLAST_HH_
# define BLAST_HH_

# include "AThrowable.hh"

class Blast : public AThrowable
{
public:
	virtual ~Blast(){}
	Blast(const Player &player, const Angle &a);
	virtual void		move();
	virtual void		print(Graphics &g) const;
};

#endif /* !BLAST_HH_ */
