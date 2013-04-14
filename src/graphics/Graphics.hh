//
// Graphics.hh for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by sebastien berton
// Login   <berton_s@epitech.net>
//
/* Started on  Tue Mar  5 17:57:15 2013 sebastien berton
** Last update Sat Mar 16 22:09:17 2013 Brunier Jean
*/

#ifndef	GRAPHICS_HH_
# define GRAPHICS_HH_

# include <SDL/SDL.h>
# include "Position.hh"
# include "Angle.hh"

class Graphics
{
private:
  SDL_Surface	*_screen;
  bool		_fs;

public:
  Graphics(int h, int w);
  ~Graphics();
  void	switchFS();
  void	printScreen();
  void	resetScreen(int color);
  void	square(Position const &pos1, Position const &pos3, int color);
  void	sponge(Position const &pos, Distance const &ray, int nb,
      Distance &size, const Angle &angle, int color);
  void	circle(Position const &pos, const Distance &size, int color);
  void	line(Position const &pos1, Position const &pos2, int color);
  void	printPixel(Position const &pos, int color);
};

#endif /* GRAPHICS_HH_ */
