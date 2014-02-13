//
// Mutex.cpp for havetofly in /home/brunie_j/local/my/havetofly
//
// Made by rebecca pang
// Login	 <pang_r@epitech.net>
//
// Started on	Tue Apr 16 13:55:25 2013 rebecca pang
// Last update Wed Apr 17 00:27:41 2013 Brunier Jean
//
#include "Mutex.hh"

Mutex::Mutex()
{
	pthread_mutex_init(&_mutex, NULL);
}

void	Mutex::lock()
{
	pthread_mutex_lock(&_mutex);
}

void	Mutex::unlock()
{
	pthread_mutex_unlock(&_mutex);
}

bool	Mutex::trylock()
{
	return (pthread_mutex_trylock(&_mutex));
}
