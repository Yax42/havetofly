//
// GameLoader.cpp for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 12:14:35 2013 Brunier Jean
// Last update Thu Apr 18 23:03:31 2013 Brunier Jean
//

#include "GameLoader.hh"
#include "Input.hh"
#include "Game.hh"
#include "Input.hh"
#include "Mutex.hh"


GameLoader::GameLoader(int h, int w, Mutex &mutex) : ALoop(2), _h(h), _w(w), _ret(true), _mutex(mutex)
{
}

bool	GameLoader::iterLoop()
{
  bool		ret;
  Input		*input = Input::get();
  Game		*game = Game::create(_h, _w);

  input->update();
  _mutex.unlock();
  for (int i = 0; i < input->nbCtrl(); i++)
    game->add(Position(40 + i * 5, i % 2 * 400 + 50), (i % 2) * 2, input->getCtrlKey(i));
  game->add(Position(300, 300), ((input->nbCtrl() % 2) * 2), input->getKBKey());
  game->loop();
  ret = game->join();
  _mutex.lock();
  Game::destroy();
  return (ret);
}
