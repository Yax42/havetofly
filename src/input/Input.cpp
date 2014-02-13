//
// Input.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 13 22:34:51 2013 Brunier Jean
// Last update Mon May 06 23:36:27 2013 Brunier Jean
//

#include <iostream>

#include "Input.hh"
#include "MyTime.hh"
#include "Exception.hh"

Input	*Input::_inst = NULL;

/*************/
/* SINGLETON */
/*************/
void	Input::create()
{
	if (_inst == NULL)
		_inst = new Input();
}

Input	*Input::get()
{
	return (_inst);
}

void	Input::destroy()
{
	if (_inst != NULL)
		{
			delete _inst;
			_inst = NULL;
		}
}

/***************/
/* CONSTRUCTOR */
/***************/
Input::~Input()
{
	for (int i = 0; i < NB_CTRL; i++)
		delete _ctrl[i];
}

Input::Input() : _quitKey(false)
{
	for (int i = 0; i < NB_CTRL; i++)
		_ctrl.push_back(new Controler(i));
	for (int i = 0; i < SDLK_LAST; i++)
		_kb[i] = 0;
}

/***********/
/* GETTERS */
/***********/
bool	Input::isQuit()
{
	return (_quitKey);
}

bool		Input::operator[](int i)
{
	if (_kb[i])
		{
			_kb[i] = 0;
			return (true);
		}
	return (false);
}

bool		Input::operator()(int i)
{
	return (_kb[i]);
}

/***********/
/* GET_KEY */
/***********/
Key	Input::getKBKey()
{
	Key	k;

	k.ptr(Key::HOR) = &_axe[0];
	k.ptr(Key::VERT) = &_axe[1];
	k.ptr(Key::A) = &_kb[SDLK_h];
	k.ptr(Key::X) = &_kb[SDLK_j];
	k.ptr(Key::B) = &_kb[SDLK_k];
	k.ptr(Key::Y) = &_kb[SDLK_l];
	k.ptr(Key::R) = &_kb[SDLK_LSHIFT];
	k.ptr(Key::L) = &_kb[SDLK_SPACE];
	return (k);
}

int	Input::nbCtrl() const
{
	int	nb = 0;
	for (int i = 0; i < NB_CTRL; i++)
		if (_ctrl[i]->isOk())
			nb++;
	return (nb);
}

Key	Input::getCtrlKey(int id)
{
	int	nb = 0;
	int	i;

	for (i = 0; i < NB_CTRL; i++)
	{
		if (_ctrl[i]->isOk())
			{
				if (nb == id)
			break ;
	else
		nb++;
			}
	}
	return (_ctrl[i]->getKey());
}

void	Input::saveKey(int id) const
{
	_ctrl[id]->saveKey();
}

/*******/
/* ACT */
/*******/
void		Input::update()
{
	for (int i = 0; i < NB_CTRL; i++)
		_ctrl[i]->update();
}

void	Input::proc()
{
	for (int i = 0; i < NB_CTRL; i++)
		_ctrl[i]->proc();
	while(SDL_PollEvent(&_event))
		{
			switch(_event.type)
			{
				case SDL_KEYDOWN:
					_kb[_event.key.keysym.sym] = 1;
					break;
				case SDL_KEYUP:
					_kb[_event.key.keysym.sym] = 0;
					break;
				case SDL_QUIT:
					_quitKey = true;
					break;
			}
		}
	_axe[0] = (_kb[SDLK_d] ? 1000 : (_kb[SDLK_a] ? -1000 : 0));
	_axe[1] = (_kb[SDLK_w] ? -1000 : (_kb[SDLK_s] ? 1000 : 0));
}
int		Input::getLastBut(int id)
{
	return (_ctrl[id]->getLastBut());
}

char		*Input::getPatern(int id)
{
	return (_ctrl[id]->getPatern());
}
