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
	Wait			_wait;
	pthread_t		_thread;
	bool			_isThread;

public:
	ALoop(int fps, bool isThread = true);
	virtual ~ALoop() {}
	void			loop();
	bool			join();
	void			quit();
private:
	bool			actualLoop();
	static void		*startThreadWrapper(void *);
	virtual bool		ifLoop();
	virtual bool		iterLoop() = 0;
	virtual void		initLoop();
	virtual void		endLoop();
};

#endif /* !ALOOP_HH_ */
