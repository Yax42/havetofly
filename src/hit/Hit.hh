//
// Hit.hh for hit in /home/brunie_j/local/my/havetofly/src/hit
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 22:46:44 2013 Brunier Jean
// Last update Sun May 05 21:56:03 2013 Brunier Jean
//

#ifndef HIT_HH_
# define HIT_HH_

# include <list>
# include "Hitbox.hh"

class Player;

class Hit
{
public:
	enum
		{
			ORIENT,
			NONE,
			WALL,
		};
private:
	int				_stun;
	Position			_speed;
	const int			&_orient;
	int				_hitLagg;
	bool				_isThrowable;
	int				_type;
	bool				_addStun;
	std::list<Hitbox>		_hb;
	std::list<Player const*>	_players;

public:
	Hit(int stun, const Position &speed, const int &orient,
			int hitLagg, bool isThrowable, int type, bool addStun = false);
	~Hit() {}
	bool	isThrowable() const;
	int	go(Player &ennemy) const;
	bool	focus(Player &ennemy);
	void	reset();
	void	add(float ray, const Position &center, const Position &playerPos);
	void	print(Graphics &g) const;
	int	hitLagg() const;
};

#endif /* !HIT_HH_ */
