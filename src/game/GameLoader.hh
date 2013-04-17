//
// GameLoader.hh for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 12:14:22 2013 Brunier Jean
// Last update Wed Apr 17 17:55:26 2013 Brunier Jean
//

#ifndef GAMELOADER_HH_
# define GAMELOADER_HH_

# include "ALoop.hh"

class GameLoader : public ALoop
{
private:
  int		_h;
  int		_w;
  bool		_ret;

public:
  virtual ~GameLoader() {}
  GameLoader(int w, int h);
private:
  virtual bool			iterLoop();
};

#endif /* !GAMELOADER_HH_ */
