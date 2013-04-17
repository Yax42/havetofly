//
// Input.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 22:34:51 2013 Brunier Jean
// Last update Wed Apr 17 18:06:06 2013 Brunier Jean
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
Input::Input() : ALoop(60)
{
  for (int i = 0; i < SDLK_LAST; i++)
    _kb[i] = 0;
}

/********/
/* LOOP */
/********/
bool	Input::iterLoop()
{
  proc();
  if ((*this)[SDLK_o] && _kb[SDLK_LALT])
    update();
  return (true);
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
  k.ptr(Key::B) = &_kb[SDLK_j];
  k.ptr(Key::X) = &_kb[SDLK_k];
  k.ptr(Key::Y) = &_kb[SDLK_l];
  k.ptr(Key::R) = &_kb[SDLK_i];
  k.ptr(Key::L) = &_kb[SDLK_o];
  return (k);
}

int	Input::nbCtrl() const
{
  return (_ctrl.size() + _jeanCtrl.isOk());
}

Key	Input::getCtrlKey(unsigned long id)
{
  Key	k;

  if (_ctrl.size() == id)
    return (_jeanCtrl.getKey());
  if (_ctrl.size() > id)
    throw(Exception("Controler missing."));
  k.ptr(Key::HOR) = &_ctrl[id].axe[0];
  k.ptr(Key::VERT) = &_ctrl[id].axe[1];
  k.ptr(Key::A) = &_ctrl[id].button[0];
  k.ptr(Key::B) = &_ctrl[id].button[1];
  k.ptr(Key::X) = &_ctrl[id].button[2];
  k.ptr(Key::Y) = &_ctrl[id].button[3];
  k.ptr(Key::R) = &_ctrl[id].button[2];
  k.ptr(Key::L) = &_ctrl[id].button[3];
  return (k);
}

/*******/
/* ACT */
/*******/
void		Input::update()
{
  std::cout << SDL_NumJoysticks() << std::endl;
  _jeanCtrl.update();
  for (int i = _ctrl.size(); i < SDL_NumJoysticks(); i++)
    {
      _ctrl.resize(i + 1);
      _ctrl[i].js = SDL_JoystickOpen(i);
      _ctrl[i].button.resize(SDL_JoystickNumButtons(_ctrl[i].js));
      _ctrl[i].axe.resize(SDL_JoystickNumAxes(_ctrl[i].js));
      _ctrl[i].hat.resize(SDL_JoystickNumHats(_ctrl[i].js));
    }
}

void	Input::proc()
{
  _jeanCtrl.proc();
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
	case SDL_JOYBUTTONDOWN:
	  _ctrl[_event.jbutton.which].button[_event.jbutton.button] = 1;
	  break;
	case SDL_JOYBUTTONUP:
	  _ctrl[_event.jbutton.which].button[_event.jbutton.button] = 0;
	  break;
	case SDL_JOYAXISMOTION:
	  _ctrl[_event.jaxis.which].axe[_event.jaxis.axis] = _event.jaxis.value;
	  break;
	case SDL_JOYHATMOTION:
	  _ctrl[_event.jball.which].hat[_event.jhat.hat] = _event.jhat.value;
	  break;
	case SDL_QUIT:
	  _quitKey = true;
	  break;
      }
    }
  _axe[0] = (_kb[SDLK_d] ? 1000 : (_kb[SDLK_a] ? -1000 : 0));
  _axe[1] = (_kb[SDLK_w] ? -1000 : (_kb[SDLK_s] ? 1000 : 0));
}