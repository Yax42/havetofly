//
// SDL_Graphics.hh for src in /home/brunie_j/svn/nibbler/nibbler-2016-lu_a/src
//
// Made by sebastien berton
// Login   <berton_s@epitech.net>
//
/* Started on  Wed Mar  6 14:07:26 2013 sebastien berton
** Last update Wed Mar 13 15:11:57 2013 Brunier Jean
*/

#ifndef	SDL_GRAPHICS_HH_
# define SDL_GRAPHICS_HH_

# include <SDL/SDL.h>

# include "AGraphics.hh"

class SDL_Graphics : public AGraphics
{
private:
  SDL_Surface	*_screen;
  SDL_Event	_event;

public:
  SDL_Graphics(int y, int x);
  ~SDL_Graphics();
  virtual void	printScreen();
  virtual void	resetScreen(int color);
  virtual bool	checkEvent(Snake &s);
  virtual void	printPixel(Position const &pos, int color);
};

#endif	/* SDL_GRAPHICS_HH_ */
