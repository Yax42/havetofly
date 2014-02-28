//
// Bones.hh for human in /home/brunie_j/local/my/havetofly/src/human
// // Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 16:06:02 2013 Brunier Jean
// Last update Sun Apr 28 14:56:55 2013 Brunier Jean
//

#ifndef BONES_HH_
# define BONES_HH_

# include "Position.hh"


class Player;
class Graphics;

class Bones
{
public:
	enum
		{
			FOOT1,
			KNEE1,
			HAND1,
			ELBOW1,
			FOOT2,
			KNEE2,
			HAND2,
			ELBOW2,
			HEAD,
			BODY,
			COUNT
		};

private:
	Player			&_player;
	int				_color2;
public:
	static const int	Size[Bones::COUNT];
private:
	Position		_pos[Bones::COUNT];
	Angle			_angle[Bones::COUNT];
public:
	Angle			angle[Bones::COUNT];

public:
	Bones(Player &player, int color2);
	~Bones();
	void			print(Graphics &g);
	const Position	&operator[](int id) const;
private:
	void			check();
};

#endif /* !BONES_HH_ */
