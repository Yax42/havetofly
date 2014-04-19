//
// Game.hh for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 13 15:34:23 2013 Brunier Jean
// Last update Sun May 12 15:34:16 2013 Brunier Jean
//

#ifndef GAME_HH_
# define GAME_HH_

# include <list>
# include "MyTime.hh"
# include "Player.hh"
# include "Wait.hh"
# include "ALoop.hh"
# include "APrintable.hh"
# include "SetKeys.hh"

typedef std::list<Player *> Players;

class Game : public APrintable
{
public:
	static const int	deep;
	static const int	freeThrow;
	static const int	centerHeartHeight;
	static const int	centerHeartRay;
	static const Position	centerHeart;

private:
	int		_height;
	int		_width;
	Players	_players;
	int		_alone;
	SetKeys	_setKeys;
	int		_time;
	bool	_ceilingOn;

/* SINGLETON */
private:
	static Game		*_inst;
private:
	virtual ~Game();
	Game(int height, int width);
	Game(const Game &other);
	Game &operator=(const Game &other);
public:
	static Game		*create(int h, int w);
	static Game		*get();
	static void		destroy();

/* GETTERS */
public:
	void			add(const Position &, int team, const Key &k, int color);
	static int		h();
	static int		w();
	static int		time();
	static bool		isCeilingOn() { return _inst->_ceilingOn; }
	static void		turnCeiling(bool v) { _inst->_ceilingOn = v; }
	/*
	static Position	center() const;
	*/
	static Players	&players();
	static void		killAll();

/* LOOP */
private:
	bool			manyTeams() const;
	virtual bool		ifLoop();
	virtual bool		iterLoop();
	virtual void		initLoop();
/* PRINTABLE */
public:
	virtual void		print(Graphics &g);
};

#endif /* !GAME_HH_ */
