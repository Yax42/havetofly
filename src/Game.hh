//
// Game.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 15:34:23 2013 Brunier Jean
// Last update Sat Apr 13 16:10:27 2013 Brunier Jean
//

#ifndef GAME_HH_
# define GAME_HH_

# include <sys/timeb.h>
# include <list>
# include "MyTime.hh"
# include "Player.hh"

typedef std::list<Player> Players;
class Game
{
private:
  int			_height;
  int			_with;
  std::list<Player>	_players;
  timeb			_t1;
  timeb			_t2;

public:
  ~Game(){}
  Game();
  Game(int width, int height);
  void		add(const Position &, int team);
  void		wait();
  void		loop();

};

#endif /* !GAME_HH_ */
