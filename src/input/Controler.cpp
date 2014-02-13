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
#ifdef WIN32
	#include <stdlib.h>
	#include <SDL/SDL.h>
#else
	#include <unistd.h>
#endif

#include "MyTime.hh"
#include "Exception.hh"
#include "Controler.hh"

#define STICK_TO_SPEED(x)	(x >> 5)

#define clean()			\
{						\
	_joystick = NULL;	\
	_axe.clear();		\
	_but.clear();		\
	return;				\
}

Controler::~Controler()
{
	clean();
}

Controler::Controler(int id) : _id(id)
{
	_joystick = NULL;
	_patern[0] = 0;
	_patern[1] = 1;
	for (int i = 2; i < 8; i++)
		_patern[i] = i - 2;
	_lastBut = -1;
	update();
	_null = 0;
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
	std::string		name;

	if (SDL_NumJoysticks() > 0)
	{
		_joystick = SDL_JoystickOpen(_id); // on l'assigne au numéro 0

		tmp = SDL_JoystickNumAxes(_joystick);
		if (tmp < 2 || tmp > 50)
			clean();
		_axe.resize(tmp);
		tmp = SDL_JoystickNumButtons(_joystick);
		if (tmp < 6 || tmp > 80)
			clean();
		_but.resize(tmp);
		name = SDL_JoystickName(_id);
		_name[name.copy(_name, name.length(), 0)] = '\0';
	}
	else
	{
		clean();
	}
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
	if (!isOk())
		return ;
	SDL_Event evenements;

	switch(evenements.type)
	{
		case SDL_JOYBUTTONDOWN:
			_lastBut = evenements.jbutton.button;
			_but[evenements.jbutton.button] = 1;
			break;
		case SDL_JOYBUTTONUP:
			_but[evenements.jbutton.button] = 0;
			break;
		case SDL_JOYAXISMOTION:
			if(evenements.jaxis.axis == 0)	
			_axe[evenements.jaxis.axis] = STICK_TO_SPEED(evenements.jaxis.value);
			break;
	}
}

/**********/
/* CONFIG */
/**********/
Key			Controler::getKey()
{
	Key			k;
	/*std::stringstream	stm;
	int			fd;

	stm << ".config/" << _name;

	if (_fd == -1 ||
			(fd = open(stm.str().c_str(), O_RDONLY)) == -1)
		{
			for (int i = 0; i < 8; i++)
				k.ptr(i) = &_null;
			return (k);
		}

	read(fd, _patern, sizeof(_patern));
	for (int i = 0; i < 2; i++)
		{
			if (_patern[i] == -1)
	k.ptr(i) = &_null;
			else
	k.ptr(i) = &_axe[_patern[i]];
		}
	for (int i = 2; i < 8; i++)
		{
			if (_patern[i] == -1)
	k.ptr(i) = &_null;
			else
	k.ptr(i) = &_but[_patern[i]];
		}
	close(fd);*/
	return (k);
}

void		Controler::saveKey() const
{
	/*if (_fd == -1)
		return ;

	int			fd;
	std::stringstream	stm;

	mkdir(".config", 0666);
	stm << ".config/" << _name;
	fd = open(stm.str().c_str(), O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		throw(Exception("Cannot create/open file in .config."));
	write(fd, _patern, sizeof(_patern));
	close(fd);*/
}

/***************/
/* LAST BUTTON */
/***************/


char		*Controler::getPatern()
{
	return (_patern);
}

int		Controler::getLastBut()
{
	int		tmp = _lastBut;
	_lastBut = -1;
	return (tmp);
}
