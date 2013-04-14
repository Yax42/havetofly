//
// Input.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 22:34:51 2013 Brunier Jean
// Last update Sun Apr 14 11:18:27 2013 Brunier Jean
//

#include "Input.hh"
#include "MyTime.hh"
#include "Exception.hh"

bool	Input::_quitKey = false;

Input::Input() : _quit(false), _wait(60)
{
  for (int i = 0; i < SDLK_LAST; i++)
    _kb[i] = 0;
  update();
}

void	Input::loop()
{
  while (!_quit)
    {
      proc();
      if ((*this)[SDLK_o] && _kb[SDLK_LALT])
	update();
      _wait.proc();
    }
}

void	Input::quit()
{
  _quit = true;
}

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

Key	Input::getKBKey()
{
  Key	k;

  k[Key::HOR] = _axe[0];
  k[Key::VERT] = _axe[1];
  k[Key::A] = _kb[SDLK_h];
  k[Key::B] = _kb[SDLK_j];
  k[Key::X] = _kb[SDLK_k];
  k[Key::Y] = _kb[SDLK_l];
  k[Key::R] = _kb[SDLK_i];
  k[Key::L] = _kb[SDLK_o];
  return (k);
}

Key	Input::getCtrlKey(unsigned long id)
{
  Key	k;

  if (_ctrl.size() >= id)
    throw(Exception("Controler missing."));

  k[Key::HOR] = _ctrl[id].axe[0];
  k[Key::VERT] = _ctrl[id].axe[1];
  k[Key::A] = _ctrl[id].button[0];
  k[Key::B] = _ctrl[id].button[1];
  k[Key::X] = _ctrl[id].button[2];
  k[Key::Y] = _ctrl[id].button[3];
  k[Key::R] = _ctrl[id].button[2];
  k[Key::L] = _ctrl[id].button[3];
  return (k);
}

void		Input::update()
{
  _ctrl.resize(SDL_NumJoysticks());
  for (int i = _ctrl.size(); i < SDL_NumJoysticks(); i++)
    {
      _ctrl[i].js = SDL_JoystickOpen(i);
      _ctrl[i].button.resize(SDL_JoystickNumButtons(_ctrl[i].js));
      _ctrl[i].axe.resize(SDL_JoystickNumAxes(_ctrl[i].js));
      _ctrl[i].hat.resize(SDL_JoystickNumHats(_ctrl[i].js));
    }
}

void	Input::proc()
{
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
  _axe[1] = (_kb[SDLK_w] ? 1000 : (_kb[SDLK_s] ? -1000 : 0));
}
