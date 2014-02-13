//
// Wait.cpp for util in /home/diallo_e/tmp/havetofly/src/util
//
// Made by Brunier Jean
// Login\t <brunie_j@epitech.net>
//
// Started on	Sun Apr 14 01:03:17 2013 Brunier Jean
// Last update Wed Apr 24 16:50:58 2013 aliou diallo
//

#include <iostream>
#include <SDL\SDL.h>

#include "Wait.hh"

Wait::Wait(int fps) : _fps(fps), _uspi(1000000 / fps), _nbFrames(0)
{
	GetTime(_t1);
	(void) _fps;
	(void) _nbFrames;
}

void		Wait::proc()
{
	int		time;

	GetTime(_t2);
	time = _uspi - (_t2.tv_sec - _t1.tv_sec) * 1000000 + (_t2.tv_usec - _t1.tv_usec);
	if (time > 0)
	{
		SDL_Delay(time / 1000);
	}
	GetTime(_t1);
	/*
	if (time < 0)
	{
		std::cout << " /TIME= " << time << std::endl;
		//std::cout << "  USPI: " << _uspi << " t1.s: " << _t1.tv_sec << " t1.us: " << _t1.tv_usec << " t2.s: " << _t2.tv_sec << " t2.us: " << _t2.tv_usec << std::endl;
	}
	*/
}