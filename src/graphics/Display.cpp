//
// Display.cpp for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 14:43:48 2013 Brunier Jean
// Last update Wed Apr 17 19:59:45 2013 Brunier Jean
//

#include "Display.hh"
#include "Input.hh"
#include "Game.hh"

Display::Display(int h, int w) : ALoop(60), _g(h, w)
{
}

void	Display::initLoop()
{
  Input::get()->update();
}

bool	Display::ifLoop()
{
  return (!Input::get()->isQuit() && !(*Input::get())[SDLK_ESCAPE]);
}

bool	Display::iterLoop()
{
   if ((*Input::get())[SDLK_p] &&(*Input::get())(SDLK_LALT))
     _g.switchFS();
  _g.resetScreen(0xDDDDDD);
  if (Game::get() != NULL)
    for (Players::iterator i = Game::players().begin(); i != Game::players().end(); ++i)
    {
       if ((*i)->alive())
          (*i)->bones().print(_g);
    }
  _g.printScreen();
  return (true);
}

void	Display::endLoop()
{
}
