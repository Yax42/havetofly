//
// ALoop.cpp for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 11:44:03 2013 Brunier Jean
// Last update Sun Apr 21 20:26:58 2013 Brunier Jean
//

#include <sstream>
#include <SDL2/SDL.h>

#include "ALoop.hh"

ALoop::ALoop(int fps, bool isThread) : _quit(false), _printFps(false), _wait(fps), _isThread(isThread)
{
}

bool	ALoop::loop()
{
	int		ret;
	if (_isThread)
		ret = pthread_create(&_thread, 0, startThreadWrapper, this);
	else
		startThreadWrapper(this);
	return _returnVal;
}

void		*ALoop::startThreadWrapper(void *obj)
{
	ALoop	*loop = (ALoop *) obj;
	loop->_nbSec = 0;
	loop->_nbFrame = 0;
	loop->_returnVal = loop->actualLoop();
	return NULL;
}

bool		ALoop::actualLoop()
{
	initLoop();
	while (ifLoop())
	{
		if (!iterLoop() || _quit)
		{
			return (false);
			endLoop();
		}
		handleFps();
		wait();
	}
	endLoop();
	return (true);
}

bool		ALoop::join()
{
	if (!_isThread)
		return true;
	void		*ret;

	pthread_join(_thread, &ret);
	return ((bool) ret);
}

void		ALoop::endLoop()
{
}

void		ALoop::initLoop()
{
}

bool		ALoop::ifLoop()
{
	return (true);
}

void		ALoop::quit()
{
	_quit = true;
}

void		ALoop::handleFps()
{
	if (_printFps)
	{
		timeval		curtime;
		GetTime(curtime);
		if (curtime.tv_sec > _nbSec)
		{
			std::ostringstream oss;
			oss << _nbFrame;
			std::string result = "[FPS:" + oss.str() + "] "+"You'd butter fly";
			//SDL_WM_SetCaption(result.c_str(), NULL);
			std::cout << "FPS=" << result << std::endl;
			_nbSec = curtime.tv_sec;
			_nbFrame = 0;
		}
		else
			_nbFrame++;
	}
}