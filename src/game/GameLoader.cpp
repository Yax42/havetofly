//
// GameLoader.cpp for game in /home/diallo_e/tmp/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 12:14:35 2013 Brunier Jean
// Last update Wed Apr 24 17:03:09 2013 aliou diallo
//

#include "GameLoader.hh"
#include "Input.hh"
#include "Game.hh"
#include "Input.hh"
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
