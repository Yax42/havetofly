//
// Display.cpp for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 14:43:48 2013 Brunier Jean
// Last update Sun Apr 21 20:32:03 2013 Brunier Jean
//

#include "Display.hh"
#include "Input.hh"
#include "Math.hh"
#include "Game.hh"
#include "const.hh"
#include "Mutex.hh"
#include "SetKeys.hh"
#include "APrintable.hh"

APrintable	*Display::_target = NULL;
Mutex		Display::mutex;

void	Display::setTarget(APrintable *target)
{
	mutex.lock();
	_target = target;
	mutex.unlock();
}

Display::Display(int h, int w) : ALoop(120), _g(h, w)
{
}

void	Display::print()
{
	mutex.lock();
	if (_target != NULL)
	{
		_target->print(_g);
	}
	mutex.unlock();
}

void	Display::initLoop()
{
}

bool	Display::ifLoop()
{
	return (true);
}

void	Display::printBG()
{
	_g.resetScreen(0xaaee00 | MGRAD_CAP(MTIME / 10, 0, 255));
}

bool	Display::iterLoop()
{
	if ((*Input::get())[SDLK_p] &&(*Input::get())(SDLK_LALT))
		_g.switchFS();
	print();
	_g.printScreen();
	return (true);
}

void	Display::endLoop()
{
}
