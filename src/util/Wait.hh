//
// Wait.hh for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 14 01:00:39 2013 Brunier Jean
// Last update Fri Apr 19 22:20:22 2013 Brunier Jean
//

#ifndef WAIT_HH_
# define WAIT_HH_

#ifdef WIN32
	# include <time.h>
	# include <WinSock.h>
	#include <sys/timeb.h>
	#include <Windows.h>
#else
	#include <sys/time.h>
	#include <unistd.h>
#endif

#ifdef WIN32
#define GetTime(t)								\
{												\
	struct _timeb timebuffer;					\
	_ftime (&timebuffer);						\
	t.tv_sec = timebuffer.time;					\
	t.tv_usec = timebuffer.millitm * 1000;		\
}
#else
	#define GetTime(t)	gettimeofday(&t, NULL);
#endif

class Wait
{
private:
	int			_fps;
	int			_uspi;
	int			_nbFrames;
	timeval		_t1;
	timeval		_t2;

public:
	~Wait(){}
	Wait(int fps);
	void		proc();
};

#endif /* !WAIT_HH_ */
