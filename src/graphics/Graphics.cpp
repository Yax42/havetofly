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

Graphics::Graphics(int h, int w) : _h(h), _w(w)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw(Exception("Cannot init SDL"));
  _fs = false;
    _screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_INIT_JOYSTICK);
  SDL_JoystickEventState(SDL_ENABLE);
  SDL_WM_SetCaption("You'd butter fly", NULL);
}

int	Graphics::h()
{
  return (_h);
}

int	Graphics::w()
{
  return (_w);
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

void	Graphics::resetScreen(const Color &color)
{
  SDL_FillRect(_screen, NULL, color.getInt());
}


/**********/
/* SQUARE */
/**********/
void		Graphics::square(Position const &pos1, Position const &pos3, const Color &color)
{
  Position	tmp((pos3 - pos1) / 2);
  Position	pos2(Position(tmp.angle() + Math::toRad(90), tmp.distance()) + tmp + pos1);
  Position	pos4(Position(tmp.angle() + Math::toRad(-90), tmp.distance()) + tmp + pos1);

  Graphics::line(pos1, pos2, color);
  Graphics::line(pos3, pos2, color);
  Graphics::line(pos3, pos4, color);
  Graphics::line(pos1, pos4, color);
}

void		Graphics::rectangle(Position const &pos1, Position const &pos3, const Color &color)
{
  Position	pos2(pos1.yDist(), pos3.xDist());
  Position	pos4(pos3.yDist(), pos1.xDist());

  Graphics::line(pos1, pos2, color);
  Graphics::line(pos3, pos2, color);
  Graphics::line(pos3, pos4, color);
  Graphics::line(pos1, pos4, color);
}

void		Graphics::rectangleLaid(Position const &pos1, Position const &pos3, const Color &color1, const Color &color2)
{
  rectangle(pos1 - 1, pos3 - 1, color1);
  rectangle(pos1, pos3, color2);
  rectangle(pos1 + 1, pos3 + 1, color1);
}

void		Graphics::rectangleFull(Position const &pos1, Position const &pos3, const Color &color)
{
  for (int i = pos1.x(); i < pos3.x(); i++)
    for (int j = pos1.y(); j < pos3.y(); j++)
      printPixel(Position(j, i), color);
}

/**********/
/* CIRCLE */
/**********/
void		Graphics::sponge(Position const &pos, Distance const &ray, int nb, const Distance &size, const Angle &angle, const Color &color)
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

void		Graphics::circle(Position const &pos, const Distance &size, const Color &color)
{
  Position	pxPos;
  Distance	max = size * Math::maxRad;

  for (Distance i = 0; i < max; i += 1)
    {
      pxPos.x(size * Math::cos(i / size));
      pxPos.y(size * Math::sin(i / size));
      pxPos += pos;
      printPixel(pxPos, color);
    }
}

void		Graphics::circleFull(Position const &pos, const Distance &size, const Color &color)
{
  Position	pxPos;
  Distance	max = size * Math::maxRad;

  for (Distance i = 0; i < max; i += 1)
    {
      pxPos.x(size * Math::cos(i / size));
      pxPos.y(size * Math::sin(i / size));
      pxPos += pos;
      line(pxPos, pos, color);
    }
}

void		Graphics::circleLaid(Position const &pos, const Distance &size, const Color &color, const Color &color2)
{
  circle(pos, size - 1, color);
  circle(pos, size, color2);
  circle(pos, size + 1, color);
}
void		Graphics::circlePart(Position const &pos, const Distance &ray,
      const Angle &from, const Angle &size, const Color &color)
{
  Position	pxPos;
  Distance	max = ray * size;

  for (Distance i = 0; i < max; i += 1)
    {
      pxPos.x(ray * Math::cos((i / ray) + from));
      pxPos.y(ray * Math::sin((i / ray) + from));
      pxPos += pos;
      printPixel(pxPos, color);
    }
}

/********/
/* LINE */
/********/
void		Graphics::line(Position const &pos1, Position const &pos2, const Color &color)
{
  Position	vect = pos2 - pos1;
  Angle		angle = vect.angle();
  int		range = vect.distance().intVal();

  for (int i = 0; i <= range; i++)
    printPixel(pos1 + Position(angle, i), color);
}

void		Graphics::line(Position const &pos1, Position const &pos2, const Color &color, int thick)
{
  /*
  if (pos1.x() == pos2.x() && pos1.y() == pos2.y())
    return ;
  */
  //std::cout << pos1 << pos2 << std::endl;
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
    Position const &pos3, const Color &color)
{
  line(pos1, pos2, color);
  line(pos2, pos3, color);
}

/*
void		Graphics::bend(Position const &pos1, const Distance &ray1,
	Position const &pos2, const Distance &ray2, const Color &color)
{
  curveLine(pos1, Circle(pos1, ray1) == Circle(pos2, ray2), pos2, color);
}*/

void	Graphics::printPixel(Position const &pos, const Color &color)
{
  if (pos.x() >= 0 && pos.x() <_screen->w && pos.y() >= 0 && pos.y() <_screen->h)
  {
    *(static_cast<int *> (_screen->pixels) + pos.y() * _screen->pitch / 4 + pos.x()) = color.getInt();
  }
//  std::cout << pos.x() << " " << pos.y() << std::endl;
}
