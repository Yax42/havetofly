//
// Player.hh for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 20:28:59 2013 Brunier Jean
// Last update Sun May 05 18:42:09 2013 Brunier Jean
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <vector>
# include <list>

# include "IAction.hh"
# include "Bones.hh"
# include "Position.hh"
# include "Key.hh"
# include "IThrowable.hh"

# include "Hit.hh"
# include "Event.hh"

# include "MovePlayer.hh"

typedef std::list<IThrowable *>::iterator Throws;

class Player
{
private:
	Position			_pos;
	bool				_alive;
	int				_team;
	Key				_keys;
	int				_color;
public:
	const Key			&key;
private:
	int				_orient;
	Bones				_bones;
	MovePlayer			_mp;
	std::vector<bool>		_event;
	std::vector<IAction*>		_action;
	std::list<IThrowable *>	_throwables;
	Position			_speed;
	IAction			*_doing;
	Hit const			*_hit;

private:
	Player	&operator=(const Player &other);
	Player(const Player &other);
public:
	Player(const Position &pos, int team, const Key &k, int color);
	~Player();

	/* PROCESS */
	void			init();
	void			move();
	void			procHit();
	void			process();
	void			upKeys();
	void			hit(const Hit *hit);

	/* SETTERS */
	void			operator=(Position const &speed);
	int			operator()(int event);
	//int			key(int k);
	void			orient(int o);
	void			tp(const Position &dir);

	/* SPEED */
	float			sx() const;
	float			sy() const;
	void			sx(float);
	void			sy(float);
	Position const	&speed() const;

	/* POSITION */
	Position const	&pos() const;
	int			x() const;
	int			y() const;

	/* ACTION */
	void			doThrow(IThrowable *item);
	int			currentAction() const;
	IAction		*operator[](int action);
	void			setAction(int id, int initVal = 0);

	/* GETTERS */
	int			closeWall() const;
	Position 		closePos() const;
	Bones			&bones();
	const Bones		&bones() const;
	void			kill();
	bool			alive() const;
	int			team() const;
	int			color() const;
	const int		&orient() const;
	const std::list<Hitbox>	&getHB() const;
	operator const Hitbox() const;
	void			print(Graphics &g);
};

#endif /* !PLAYER_HH_ */
