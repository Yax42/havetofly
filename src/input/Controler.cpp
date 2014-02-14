//
// Controler.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 18 17:34:29 2013 Brunier Jean
// Last update Tue May 07 10:03:10 2013 Brunier Jean
//

#include <cstdio>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#ifdef WIN32
	#include <stdlib.h>
#else
	#include <unistd.h>
#endif

#include "MyTime.hh"
#include "Exception.hh"
#include "Controler.hh"

int			Controler::Null = 0;

#define STICK_TO_SPEED(x)	(x >> 5)

#define deadClean()						\
{										\
	clean();							\
	return;								\
}

Controler::~Controler()
{
	clean();
}

Controler::Controler(int id) : _id(id)
{
	_joystick = NULL;
	for (int i =0; i < Key::COUNT; i++)
		_keys[i] = 0;
	update();
}

void		Controler::clean()
{
	if (_joystick != NULL)
		SDL_JoystickClose(_joystick);
	_joystick = NULL;
	for (int i =0; i < Key::COUNT; i++)
		_keys[i] = 0;
}

bool	Controler::isOk() const
{
	return _joystick != NULL;
}

/***********/
/* PROCESS */
/***********/
void			Controler::update()
{
	int			tmp;

	if (SDL_NumJoysticks() <= _id)
		deadClean();
	/*if (SDL_JoystickOpened(_id))
		deadClean();*/
	if (!SDL_JoystickGetAttached(_joystick))
		_joystick = SDL_JoystickOpen(_id); // on l'assigne au numéro 0
	if (_joystick == NULL)
		deadClean();
	/*char			tmp;
	std::stringstream	stm;

	stm << "/dev/input/js" << _id;
	if (access(stm.str().c_str(), R_OK) == -1)
		clean();
	if (_fd != -1)
		return ;
	_fd = open(stm.str().c_str(), O_RDONLY);
	if (_fd == -1)
		clean();
	ioctl(_fd, JSIOCGAXES, &tmp);
	if (tmp < 2 || tmp > 50)
		clean();
	_axe.resize(tmp);
	ioctl(_fd, JSIOCGBUTTONS, &tmp);
	if (tmp < 6 || tmp > 80)
		clean();
	_but.resize(tmp);
	ioctl(_fd, JSIOCGNAME(sizeof(_name)), &_name);

	fcntl(_fd, F_SETFL, O_NONBLOCK);*/
	//std::cout << _name << " Axe[" << _axe.size() <<
	//	"] Buttons [" << _but.size() << "]" << std::endl;
}

void	Controler::proc()
{
	_keys[0] = SDL_JoystickGetAxis(_joystick, 0);
	_keys[1] = SDL_JoystickGetAxis(_joystick, 1);
	for (int i = 0; i < 6; i++)
		_keys[i+2] = SDL_JoystickGetButton(_joystick, i);
	
}

/**********/
/* CONFIG */
/**********/
Key			Controler::getKey()
{
	Key			k;

	if (!isOk())
	{
		for (int i = 0; i < Key::COUNT; i++)
			k.ptr(i) = &Null;
	}
	else
	{
		for (int i = 0; i < Key::COUNT; i++)
			k.ptr(i) = &_keys[i];
	}
	return (k);
}

void		Controler::saveKey() const
{
}

/***************/
/* LAST BUTTON */
/***************/


char		*Controler::getPatern()
{
	return (NULL);
}

int		Controler::getLastBut()
{
	return (0);
}
