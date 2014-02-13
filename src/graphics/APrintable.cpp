//
// APrintable.cpp for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 21 17:00:45 2013 Brunier Jean
// Last update Mon May 06 23:10:17 2013 Brunier Jean
//

#include "MyTime.hh"
#include "APrintable.hh"
#include "Input.hh"
#include "Display.hh"

void	APrintable::setPrint()
{
	Display::setTarget(this);
}

APrintable::APrintable(int fps) : _quit(false), _wait(fps)
{
}

bool	APrintable::cleanLoop(bool v)
{
	Display::setTarget(NULL);
	endLoop();
	return (v);
}

bool	APrintable::loop()
{
	initLoop();
	Display::setTarget(this);
	while (ifLoop())
		{
			if (Input_[SDLK_ESCAPE])
	return (cleanLoop(true));
			if (Input_.isQuit() ||	!iterLoop() || _quit)
	return (cleanLoop(false));
			Input::get()->proc();
			_wait.proc();
			MyTime::run();
		}
	return (cleanLoop(true));
}

void		APrintable::switchPrint(APrintable &next)
{
	if (next.loop() == false)
		quit();
	Display::setTarget(this);
}

void		APrintable::endLoop()
{
}

void		APrintable::initLoop()
{
}

bool		APrintable::ifLoop()
{
	return (true);
}

void		APrintable::quit()
{
	_quit = true;
}
