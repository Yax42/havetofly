//
// SDL_Graphics.cpp for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by sebastien berton
// Login   <berton_s@epitech.net>
//
/* Started on  Wed Mar  6 14:12:48 2013 sebastien berton
** Last update Wed Mar 20 14:44:39 2013 Brunier Jean
*/

#include "SDL_Graphics.hh"

# define	GRADUAL_CAP(x, max)	(((x) % (max * 2) >= max) ? max - (x) % max - 1 : (x) % max)
# define	ADD_TO_COLOR(c, t)	(GRADUAL_CAP((c & 0xff) + t * 5, 0xff) |				\
    					GRADUAL_CAP(((c & 0xff00) >> 8) + t * 3, 0xff) << 8 |		\
    					GRADUAL_CAP(((c & 0xff0000) >> 16) + t * 2, 0xff) << 16)

SDL_Graphics::SDL_Graphics(int y, int x) : AGraphics()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw(Exception("Cannot init SDL ):"));
  _screen = SDL_SetVideoMode(x * UNIT_SIZE, y * UNIT_SIZE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Nibbler by Lu_a, Brunie_j, Berton_s with SDL", NULL);
}

SDL_Graphics::~SDL_Graphics()
{
  SDL_Quit();
}

void	SDL_Graphics::printScreen()
{
  SDL_Flip(_screen);
}

void	SDL_Graphics::resetScreen(int color)
{
  SDL_FillRect(_screen, NULL, color);
}

bool	SDL_Graphics::checkEvent(Snake &s)
{
  bool	F2 = false;

  while (SDL_PollEvent(&_event))
    {
      if (_event.type == SDL_QUIT)
	_isFinish = true;
      else if (_event.type == SDL_KEYDOWN)
	{
	  if (_event.key.keysym.sym == SDLK_ESCAPE)
	    _isFinish = true;
	  else if (_event.key.keysym.sym == SDLK_F2)
	    F2 = true;
	  else if ((_event.key.keysym.sym == SDLK_w || _event.key.keysym.sym == SDLK_k) &&
		   (s.getDir() == LEFT || s.getDir() == RIGHT))
	    s.setDir(UP);
	  else if ((_event.key.keysym.sym == SDLK_s || _event.key.keysym.sym == SDLK_j) &&
		   (s.getDir() == RIGHT || s.getDir() == LEFT))
	    s.setDir(DOWN);
	  else if ((_event.key.keysym.sym == SDLK_d || _event.key.keysym.sym == SDLK_l) &&
		   (s.getDir() == DOWN || s.getDir() == UP))
	    s.setDir(RIGHT);
	  else if ((_event.key.keysym.sym == SDLK_a || _event.key.keysym.sym == SDLK_h) &&
		   (s.getDir() == DOWN || s.getDir() == UP))
	    s.setDir(LEFT);
	  else if (_event.key.keysym.sym == SDLK_LEFT)
	    s.goLeft();
	  else if (_event.key.keysym.sym == SDLK_RIGHT)
	    s.goRight();
	}
    }
  return (F2);
}

void	SDL_Graphics::printPixel(Position const &pos, int color)
{
  if (pos.x >= 0 && pos.x <_screen->w && pos.y >= 0 && pos.y <_screen->h)
    *(static_cast<int *> (_screen->pixels) + pos.y * _screen->pitch / 4 + pos.x) = ADD_TO_COLOR(color, MyTime::get());
}

extern "C"
{
  IGraphics *create(int y, int x)
  {
    return (new SDL_Graphics(y, x));
  }
}

