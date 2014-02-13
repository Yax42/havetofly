//
// Mutex.hh for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by rebecca pang
// Login	 <pang_r@epitech.net>
//
// Started on	Tue Apr 16 13:55:25 2013 rebecca pang
// Last update Thu Apr 18 22:47:17 2013 Brunier Jean
//

#ifndef MUTEX_H_
# define MUTEX_H_

# include <pthread.h>

class Mutex
{
private:
	pthread_mutex_t	_mutex;
public:
	~Mutex() {}
	Mutex();
	void		lock();
	void		unlock();
	bool		trylock();
};

#endif /* MUTEX */
