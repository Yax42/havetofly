//
// Graphics.cpp for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by sebastien berton
// Login   <berton_s@epitech.net>
//
/* Started on  Tue Mar  5 17:57:06 2013 sebastien berton
** Last update Sat Mar 16 22:08:43 2013 Brunier Jean
*/

#include <iostream>
#include "Graphics.hh"

#include "Exception.hh"
#include "Math.hh"

# define	GRADUAL_CAP(x, max)	(((x) % (max * 2) >= max) ? max - (x) % max - 1 : (x) % max)

Graphics::Graphics(int h, int w, bool fs)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw(Exception("Cannot init SDL"));
  if (fs)
    _screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
  else
    _screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("You'd butter fly", NULL);
}

Graphics::~Graphics()
{
  SDL_Quit();
}

void	Graphics::printScreen()
{
  SDL_Flip(_screen);
}

void	Graphics::resetScreen(int color)
{
  SDL_FillRect(_screen, NULL, color);
}

void		Graphics::square(Position const &pos1, Position const &pos3, int color)
{
  Position	tmp((pos3 - pos1) / 2);
  Position	pos2(Position(tmp.angle + Math::toRad(90), tmp.distance()) + tmp + pos1);
  Position	pos4(Position(tmp.angle + Math::toRad(-90), tmp.distance()) + tmp + pos1);

  Graphics::line(pos1, pos2, 0, color);
  Graphics::line(pos3, pos2, 0, color);
  Graphics::line(pos3, pos4, 0, color);
  Graphics::line(pos1, pos4, 0, color);
}

void		Graphics::sponge(Position const &pos, Distance const &ray, int nb, Distance &size, const Angle &angle, int color)
{
  Angle		angleOffset(Math::toRad(360) / nb);
  Position	pos1;
  Position	pos2;

  for (Angle i = angle; i < (Math::toRad(360) + angle); i += angleOffset)
    {
      pos1 = Position(i, ray - size) + pos;
      pos2 = Position(i + angleOffset / 2, ray + size) + pos;
      line(pos1, pos2, 0, color);
      pos1 = Position(i + angleOffset, ray - size) + pos;
      line(pos2, pos1, 0, color);
    }
}

void		Graphics::circle(Position const &pos, const Distance &size, int color)
{
  Position	pxPos;
  Distance	max =  Math::maxRad * size;

  for (Distance i = 0; i < max; i += 1)
    {
      pxPos.x(Math::cos(i / size) * size);
      pxPos.y(Math::sin(i / size) * size);
      pxPos += pos;
      printPixel(pxPos, color);
    }
}

void		Graphics::line(Position const &pos1, Position const &pos2, int color)
{
  Position	vect = pos2 - pos1;
  Angle		angle = vect.angle();
  Distance	range = vect.distance();

  for (int i = 0; i <= range.intVal(); i++)
    printPixel(pos1 + Position(angle, i), color);
}

void	Graphics::printPixel(Position const &pos, int color)
{
  if (pos.x() >= 0 && pos.x() <_screen->w && pos.y() >= 0 && pos.y() <_screen->h)
    *(static_cast<int *> (_screen->pixels) + pos.y() * _screen->pitch / 4 + pos.x()) = color;
}
