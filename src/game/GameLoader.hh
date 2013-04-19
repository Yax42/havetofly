//
// GameLoader.hh for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 12:14:22 2013 Brunier Jean
// Last update Fri Apr 19 12:10:32 2013 Brunier Jean
//

#ifndef GAMELOADER_HH_
# define GAMELOADER_HH_

# include "ALoop.hh"

class Mutex;

class GameLoader : public ALoop
{
private:
  int		_h;
  int		_w;
  bool		_ret;
  Mutex		&_mutex;

public:
  virtual ~GameLoader() {}
  GameLoader(int w, int h, Mutex &mutex);
private:
  virtual bool			iterLoop();
};

#endif /* !GAMELOADER_HH_ */
