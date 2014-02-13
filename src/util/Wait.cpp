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
#include "Wait.hh"
#ifdef WIN32
	#define DELAY 1000000
#else
	#define DELAY 1000000
#endif
Wait::Wait(int fps) : _fps(fps), _uspi(DELAY / fps), _nbFrames(0)
{
	(void) _fps;
	(void) _nbFrames;
	#ifdef WIN32
		struct _timeb timebuffer;
		_ftime (&timebuffer);
		_t1.tv_sec = timebuffer.time;
		_t1.tv_usec = timebuffer.millitm * 1000;
	#else
		gettimeofday(&_t1, NULL);
	#endif
}

void		Wait::proc()
{
	int		time;

	#ifdef WIN32
		struct _timeb timebuffer;
		_ftime (&timebuffer);
		_t2.tv_sec = timebuffer.time;
		_t2.tv_usec = timebuffer.millitm * 1000;
	#else
		gettimeofday(&_t2, NULL);
	#endif
	time = _uspi - (_t2.tv_sec - _t1.tv_sec) * 1000000 +
	(_t2.tv_usec - _t1.tv_usec);
	if (time > 0)
		#ifdef WIN32
			Sleep(time / 1000);
		#else
			usleep(time);
		#endif

	#ifdef WIN32
		_ftime (&timebuffer);
		_t1.tv_sec = timebuffer.time;
		_t1.tv_usec = timebuffer.millitm * 1000;
	#else
		gettimeofday(&_t1, NULL);
	#endif
		if (time < 0)
		{
		std::cout << " /TIME= " << time << std::endl;
		//std::cout << "  USPI: " << _uspi << " t1.s: " << _t1.tv_sec << " t1.us: " << _t1.tv_usec << " t2.s: " << _t2.tv_sec << " t2.us: " << _t2.tv_usec << std::endl;
		}
}
