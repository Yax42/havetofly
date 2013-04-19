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

# define	GRADUAL_CAP(x, max)	(((x) % (max * 2) >= max) ?	\
   					max - ((x) % (max) - 1 :	\
					(x) % (max))

Graphics::Graphics(int h, int w)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw(Exception("Cannot init SDL"));
  _fs = false;
    _screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_INIT_JOYSTICK);
  SDL_JoystickEventState(SDL_ENABLE);
  SDL_WM_SetCaption("You'd butter fly", NULL);
}

void	Graphics::switchFS()
{
  int	w = _screen->w;
  int	h = _screen->h;

  SDL_FreeSurface(_screen);
  _fs = !_fs;
  if (_fs)
    _screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN | SDL_INIT_JOYSTICK);
  else
    _screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_INIT_JOYSTICK);
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
  Position	pos2(Position(tmp.angle() + Math::toRad(90), tmp.distance()) + tmp + pos1);
  Position	pos4(Position(tmp.angle() + Math::toRad(-90), tmp.distance()) + tmp + pos1);

  Graphics::line(pos1, pos2, color);
  Graphics::line(pos3, pos2, color);
  Graphics::line(pos3, pos4, color);
  Graphics::line(pos1, pos4, color);
}

void		Graphics::sponge(Position const &pos, Distance const &ray, int nb, const Distance &size, const Angle &angle, int color)
{
  Ratio		angleOffset = Math::maxRad / nb;
  Ratio		goal = Math::maxRad + angle;
  Position	pos1;
  Position	pos2;

  for (Ratio i = angle; i < goal; i += angleOffset)
    {
      pos1 = Position(Angle(i), ray - size) + pos;
      pos2 = Position(Angle(i + angleOffset / 2), ray + size) + pos;
      line(pos1, pos2, color);
      pos1 = Position(Angle(i + angleOffset), ray - size) + pos;
      line(pos2, pos1, color);
    }
}

void		Graphics::circle(Position const &pos, const Distance &size, int color)
{
  Position	pxPos;
  Distance	max = size * Math::maxRad;

  for (Distance i = 0; i < max; i += 1)
    {
      pxPos.x(size * Math::cos(i / size));
      pxPos.y(size * Math::sin(i / size));
      //std::cout << (i / size).longVal() << " " << Math::sin(i / size).longVal() << std::endl;
      //std::cout << pxPos.x() << " " << pxPos.y() << std::endl;
      pxPos += pos;
      printPixel(pxPos, color);
    }
}

void		Graphics::line(Position const &pos1, Position const &pos2, int color)
{
  Position	vect = pos2 - pos1;
  Angle		angle = vect.angle();
  int		range = vect.distance().intVal();

  for (int i = 0; i <= range; i++)
    printPixel(pos1 + Position(angle, i), color);
}

void		Graphics::line(Position const &pos1, Position const &pos2, int color, int thick)
{
  Position	vect = pos2 - pos1;
  Angle		angle = vect.angle();
  Angle		angleOut[] =
    {
      vect.angle() + Angle(0, 0),
      vect.angle() + Angle(0, 0)
    };

  for (int j = 0; j < thick; j++)
    line(pos1 + Position(0, j) * angle + (Position(j / 2, 0) * angleOut[j % 2]),
         pos2 + Position(0, j) * (angle + Angle(180, 0)) + (Position(j / 2, 0) * angleOut[j % 2]), color);
}

void		Graphics::curveLine(Position const &pos1, Position const &pos2,
    Position const &pos3, int color)
{
  line(pos1, pos2, color);
  line(pos2, pos3, color);
}

/*
void		Graphics::bend(Position const &pos1, const Distance &ray1,
	Position const &pos2, const Distance &ray2, int color)
{
  curveLine(pos1, Circle(pos1, ray1) == Circle(pos2, ray2), pos2, color);
}*/

void	Graphics::printPixel(Position const &pos, int color)
{
  if (pos.x() >= 0 && pos.x() <_screen->w && pos.y() >= 0 && pos.y() <_screen->h)
  {
    *(static_cast<int *> (_screen->pixels) + pos.y() * _screen->pitch / 4 + pos.x()) = color;
  }
//  std::cout << pos.x() << " " << pos.y() << std::endl;
}
