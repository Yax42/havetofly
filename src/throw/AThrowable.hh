//
// AThrowable.hh for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Mon Apr 22 01:23:19 2013 Brunier Jean
// Last update Sun May 05 21:57:31 2013 Brunier Jean
//

#ifndef ATHROWABLE_HH_
# define ATHROWABLE_HH_

# include "Position.hh"
# include "Graphics.hh"
# include "Hit.hh"
# include "Player.hh"
# include "Math.hh"
# include "MyTime.hh"
# include "IThrowable.hh"

class AThrowable : public IThrowable
{
public:
	static const int	SIZE;
protected:
	Position		_pos;
	Position		_speed;
	bool			_alive;
	int				_orient;
	Hit				_hit;
	Player			&_player;
	int				_val1;
private:
	Position		_initPos;
	int				_count;

public:
	virtual ~AThrowable(){}
	AThrowable(const Position &pos, const Position &speed,
			int stun, const Position &hitSpeed, Player &player,
			int type = Hit::ORIENT, bool addStun = false);
	bool			isAlive() const;
	void			init();
	void			proc();
	virtual void		move();
	virtual void		effect(Player &p);
	virtual void		print(Graphics &g) const = 0;
	virtual void		printHB(Graphics &g) const;
	virtual void		effectWall() { _alive = false; }
};

#endif /* !ATHROWABLE_HH_ */
