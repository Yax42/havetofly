//
// Ball.hh for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 23 02:41:50 2013 Brunier Jean
// Last update Tue Apr 23 16:10:40 2013 Brunier Jean
//

#ifndef BALL_HH_
# define BALL_HH_

# include "AThrowable.hh"

class Ball : public AThrowable
{
public:
	virtual ~Ball(){}
	Ball(const Player &player, const Angle &a);
	virtual void		move();
	virtual void		print(Graphics &g) const;
};

#endif /* !BALL_HH_ */
