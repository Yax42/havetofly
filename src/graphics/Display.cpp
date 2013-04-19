//
// Display.cpp for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 14:43:48 2013 Brunier Jean
// Last update Fri Apr 19 12:08:48 2013 Brunier Jean
//

#include "Display.hh"
#include "Input.hh"
#include "Math.hh"
#include "Game.hh"
#include "const.hh"
#include "Mutex.hh"

Display::Display(int h, int w, Mutex &mutex) : ALoop(60), _g(h, w), _mutex(mutex)
{
}

void	Display::initLoop()
{
  _mutex.lock();
}

bool	Display::ifLoop()
{
  return (!Input::get()->isQuit() && !(*Input::get())[SDLK_ESCAPE]);
}

bool	Display::iterLoop()
{
  _mutex.lock();
  _g.resetScreen(0xaaee00 | MGRAD_CAP(MTIME / 10, 0, 255));
   if ((*Input::get())[SDLK_p] &&(*Input::get())(SDLK_LALT))
     _g.switchFS();
  if (_quit)
    return (true);
  for (Players::iterator i = Game::players().begin(); i != Game::players().end(); ++i)
    {
      if ((*i)->alive())
        {
	  (*i)->bones().print(_g);
	  for (int j = 0; j < IAction::COUNT; j++)
	    (**i)[j]->print(_g);
	  if (DEBUG & 8)
	    (**i)[(*i)->currentAction()]->printHB(_g);
	}
    }
  _mutex.unlock();
  _g.printScreen();
  return (true);
}

void	Display::endLoop()
{
}
