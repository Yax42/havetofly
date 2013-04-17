//
// GameLoader.cpp for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 12:14:35 2013 Brunier Jean
// Last update Wed Apr 17 20:53:16 2013 Brunier Jean
//

#include "GameLoader.hh"
#include "Input.hh"
#include "Game.hh"
#include "Input.hh"


GameLoader::GameLoader(int h, int w) : ALoop(2), _h(h), _w(w), _ret(true)
{
}

bool	GameLoader::iterLoop()
{
  bool		ret;
  Input		*input = Input::get();
  Game		*game = Game::create(_h, _w);

  input->update();
  for (int i = 0; i < input->nbCtrl(); i++)
    game->add(Position(40 + i * 5, i % 2 * 400 + 50), (i % 2) * 2, input->getCtrlKey(i));
  game->add(Position(300, 300), ((input->nbCtrl() % 2) * 2), input->getKBKey());
  game->loop();
  ret = game->join();
  Game::destroy();
  return (ret);
}
