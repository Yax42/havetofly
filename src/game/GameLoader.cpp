//
// GameLoader.cpp for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 12:14:35 2013 Brunier Jean
// Last update Mon Apr 29 23:22:11 2013 Brunier Jean
//

#include "GameLoader.hh"
#include "Input.hh"
#include "Game.hh"
#include "Input.hh"
#include "const.hh"
#include "Mutex.hh"


GameLoader::GameLoader(int h, int w) : ALoop(2), _h(h), _w(w), _ret(true)
{
  (void) _ret;
}

bool	GameLoader::iterLoop()
{
  static const int color[] =
    {
      0xFF0000,
      0x0000FF,
      0x005500,
      0x880088,
      0xFF00FF,
      0xFF8800
    };
  bool		ret;
  Game		*game = Game::create(_h, _w);

  _Input.update();
  if (DEBUG & 256)
    game->add(Position(400, 256), 100, _Input.getKBKey(),  color[5]);
  for (int i = 1; i <= _Input.nbCtrl(); i++)
    game->add(Position(400, 50 + i * 200), i, _Input.getCtrlKey(i - 1),  color[i]);
  game->add(Position(400, 50), 0, _Input.getKBKey(), color[0]);
  ret = game->loop();
  int cpt = 0;
  for(Players::iterator i = Game::players().begin(); i != Game::players().end(); ++i)
  {
    cpt++;
    if ((*i)->alive())
      {
	std::cout << cpt << std::endl;
      }
  }
  Game::destroy();
  return (ret);
}
