//
// GameLoader.cpp for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 12:14:35 2013 Brunier Jean
// Last update Sun Apr 21 20:12:54 2013 Brunier Jean
//

#include "GameLoader.hh"
#include "Input.hh"
#include "Game.hh"
#include "Input.hh"
#include "Mutex.hh"


GameLoader::GameLoader(int h, int w) : ALoop(2), _h(h), _w(w), _ret(true)
{
}

bool	GameLoader::iterLoop()
{
  bool		ret;
  Game		*game = Game::create(_h, _w);

  _Input.update();
  for (int i = 0; i < _Input.nbCtrl(); i++)
    game->add(Position(40 + i * 5, i % 2 * 400 + 50), (i % 2) * 2, _Input.getCtrlKey(i));
  game->add(Position(300, 300), (3 ), _Input.getKBKey());
  ret = game->loop();
  Game::destroy();
  return (ret);
}
