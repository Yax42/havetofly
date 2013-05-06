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
# include "Color.hh"

class Graphics
{
private:
  int		_h;
  int		_w;
  SDL_Surface	*_screen;
  bool		_fs;

public:
  Graphics(int h, int w);
  ~Graphics();
  void	switchFS();
  void	printScreen();
  void	resetScreen(const Color &color);
/* SQUARE */
  void	square(Position const &pos1, Position const &pos3, const Color &color);
  void	rectangle(Position const &pos1, Position const &pos3, const Color &color);
  void	rectangleFull(Position const &pos1, Position const &pos3, const Color &color);
  void	rectangleLaid(Position const &pos1, Position const &pos3, const Color &color, const Color &color2 = 0xFFFFFF);
/* CIRCLE */
  void	sponge(Position const &pos, Distance const &ray, int nb,
      const Distance &size, const Angle &angle, const Color &color);
  void	circle(Position const &pos, const Distance &size, const Color &color);
  void	circleLaid(Position const &pos, const Distance &size, const Color &color, const Color &color2 = 0xFFFFFF);
  void	circleFull(Position const &pos, const Distance &size, const Color &color);
  void	circlePart(Position const &pos, const Distance &ray,
      const Angle &from, const Angle &size, const Color &color);

/* LINE */
  void	line(Position const &pos1, Position const &pos2, const Color &color);
  void	line(Position const &pos1, Position const &pos2, const Color &color, int thick);
  void	curveLine(Position const &pos1, Position const &pos2, Position const &pos3, const Color &color);
  void	printPixel(Position const &pos, const Color &color);
  void	bend(Position const &pos1, const Distance &ray1,
	Position const &pos2, const Distance &ray2, const Color &color);
  int	h();
  int	w();
};

#endif /* GRAPHICS_HH_ */
