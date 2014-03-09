//
// Tempo.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 21 00:19:50 2013 Brunier Jean
// Last update Sun Apr 21 00:33:17 2013 Brunier Jean
//

#ifndef TEMPO_HH_
# define TEMPO_HH_

# include "AAction.hh"

class Tempo : public AAction
{
public:
	Tempo(Player &player);
	virtual ~Tempo(){}
	virtual void		init(int v = 0);
	virtual void		set(int v = 0);
	virtual void		step();
};

#endif /* !TEMPO_HH_ */
