//
// Input.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 22:34:54 2013 Brunier Jean
// Last update Sun Apr 14 10:01:25 2013 Brunier Jean
//

#ifndef INPUT_HH_
# define INPUT_HH_

# include <SDL/SDL.h>
# include <vector>

# include "Key.hh"
# include "Wait.hh"

struct Controler
{
  std::vector<int>	hat;
  std::vector<int>	axe;
  std::vector<int>	button;
  SDL_Joystick		*js;
};

class Input
{
private:
  bool				_quit;
  Wait				_wait;
  int				_kb[SDLK_LAST];
  SDL_Event			_event;
  std::vector<Controler>	_ctrl;
  int				_axe[2];
  static bool			_quitKey;

public:
  ~Input(){}
  Input();
  bool		operator[](int i);
  static bool	isQuit();
  void		loop();
  void		quit();
  void		update();
  void		proc();
  Key		getKBKey();
  Key		getCtrlKey(unsigned long id);
};

#endif /* !INPUT_HH_ */
