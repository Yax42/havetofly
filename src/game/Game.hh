//
// Game.hh for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 15:34:23 2013 Brunier Jean
// Last update Sun Apr 21 23:46:37 2013 Brunier Jean
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
private:
  int		_height;
  int		_width;
  Players	_players;
  int		_alone;
  SetKeys	_setKeys;

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
  void			add(const Position &, int team, const Key &k);
  static int		h();
  static int		w();
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
