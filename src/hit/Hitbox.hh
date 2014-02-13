//
// Hitbox.hh for hit in /home/brunie_j/local/my/havetofly/src/hit
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 15:39:05 2013 Brunier Jean
// Last update Thu Apr 18 22:18:16 2013 Brunier Jean
//

#ifndef HITBOX_HH_
# define HITBOX_HH_

# include "Position.hh"

class Graphics;
class Player;

class Hitbox
{
private:
	float			_ray;
	Position		_center;
	const Position	&_playerPos;
	const	int		&_orient;

public:
	Hitbox(float ray, const Position &center,
			const Position &playerPos, const int &orient);
	void	print(Graphics &g, int color) const;
	~Hitbox() {}
	bool		touch(const Player &player) const;
	bool		touch(const Hitbox &other) const;
};

#endif /* !HITBOX_HH_ */
