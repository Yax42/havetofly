//
// Graphics.hh for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by sebastien berton
// Login	 <berton_s@epitech.net>
//
/* Started on	Tue Mar	5 17:57:15 2013 sebastien berton
** Last update Sat Mar 16 22:09:17 2013 Brunier Jean
*/

#ifndef	GRAPHICS_HH_
# define GRAPHICS_HH_

#ifdef WIN32
	# include <time.h>
	# include <WinSock.h>
	#include <sys/timeb.h>
	#include <Windows.h>
#else
	#include <sys/time.h>
	#include <unistd.h>
#endif
# include <SDL2/SDL.h>

# include "Position.hh"
# include "Angle.hh"
# include "Color.hh"

class Graphics
{
private:
	int		_h;
	int		_w;
	int		_minX;
	int		_maxX;
	SDL_Window	*_window;
	SDL_Renderer	*_renderer;
	SDL_Surface	*_screen;
	SDL_Texture *_texture;
	bool		_fs;

public:
	~Graphics();
	Graphics(int h, int w);
	int	h();
	int	w();
	void	switchFS();
	void	printScreen();
	void	resetScreen(const Color &color);
	void	resetLocal(const Color &color);
	void	setCap(int min = 0, int max = 0);
/* SQUARE */
	void	square(Position const &pos1, Position const &pos3, const Color &color);
	void	rectangle(Position const &pos1, Position const &pos3, const Color &color);
	void	rectangleFull(Position const &pos1, Position const &pos3, const Color &color);
	void	rectangleLaid(Position const &pos1, Position const &pos3, const Color &color, const Color &color2 = 0xFFFFFF);
/* CIRCLE */
	void	sponge(Position const &pos, float ray, int nb,
			float size, const Angle &angle, const Color &color);
	void	circle(Position const &pos, float size, const Color &color);
	void	circleLaid(Position const &pos, float size, const Color &color, const Color &color2 = 0xFFFFFF);
	void	circleFull(Position const &pos, float size, const Color &color);
	void	circlePart(Position const &pos, float ray,
			const Angle &from, const Angle &size, const Color &color);

/* LINE */
	void	line(Position const &pos1, Position const &pos2, const Color &color);
	void	line(Position const &pos1, Position const &pos2, const Color &color, int thick);
	void	curveLine(Position const &pos1, Position const &pos2, Position const &pos3, const Color &color);
	void	bend(Position const &pos1, float ray1,
	Position const &pos2, float ray2, const Color &color);

/* PIXEL */
	void	printPixel(Position const &pos, const Color &color);
};

#endif /* GRAPHICS_HH_ */
