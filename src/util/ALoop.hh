//
// ALoop.hh for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 11:38:16 2013 Brunier Jean
// Last update Wed Apr 17 17:50:23 2013 Brunier Jean
//

#ifndef ALOOP_HH_
# define ALOOP_HH_

# include <pthread.h>
# include <iostream>

# include "Wait.hh"

class ALoop
{
protected:
	bool			_quit;
private:
	bool			_printFps;
	Wait			_wait;
	pthread_t		_thread;
	bool			_isThread;
	int				_nbFrame;
	int				_nbSec;
	bool			_returnVal;

public:
	ALoop(int fps, bool isThread = true);
	virtual ~ALoop() {}
	bool			loop();
	bool			join();
	void			quit();
	void			printFps(bool v) { _printFps = v; }
protected:
	void				handleFps();
	virtual bool		ifLoop();
	virtual bool		iterLoop() = 0;
	virtual void		initLoop();
	virtual void		endLoop();
	void				wait() { _wait.proc(); }
private:
	virtual bool		actualLoop();
	static void		*startThreadWrapper(void *);
};

#endif /* !ALOOP_HH_ */
