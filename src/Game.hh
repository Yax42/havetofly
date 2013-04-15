//
// Game.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 15:34:23 2013 Brunier Jean
// Last update Sun Apr 14 20:00:00 2013 Brunier Jean
//

#ifndef GAME_HH_
# define GAME_HH_

# include <list>
# include "MyTime.hh"
# include "Player.hh"
# include "Wait.hh"

typedef std::list<Player *> Players;

class Game
{
public:
  static Players	players;
  static int		h();
  static int		w();
  static bool		quit;
private:
  Wait			_wait;
  static int		_height;
  static int		_width;

public:
  ~Game();
  Game();
  Game(int height, int width);
  bool		manyTeams() const;
  void		add(const Position &, int team, const Key &k);
  bool		loop();

};

#endif /* !GAME_HH_ */
