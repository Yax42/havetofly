//
// Graphics.cpp for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by sebastien berton
// Login	 <berton_s@epitech.net>
//
/* Started on	Tue Mar	5 17:57:06 2013 sebastien berton
** Last update Sat Mar 16 22:08:43 2013 Brunier Jean
*/

#include <iostream>
#include <sstream>

#include "Graphics.hh"
#include "Exception.hh"
#include "Math.hh"
#include "Wait.hh"

#define	GRADUAL_CAP(x, max)		(((x) % (max * 2) >= max) ?	\
	 					max - ((x) % (max) - 1 :	\
					(x) % (max))

#define printPixelUnsafe(y, x, color)					\
	{									\
		*(static_cast<int *> (_screen->pixels) + y *			\
			_screen->pitch / 4 + x) = color;					\
	}

Graphics::~Graphics()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

Graphics::Graphics(int h, int w) : _h(h), _w(w), _minX(0), _maxX(w)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) == -1)
		throw(Exception("Cannot init SDL"));
	SDL_CreateWindowAndRenderer(w, h, SDL_INIT_JOYSTICK, &_window, &_renderer);
	if (!_window && !_renderer)
		throw(Exception("Cannot create window or renderer fail."));
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); 
	SDL_RenderClear(_renderer); 
	SDL_RenderPresent(_renderer);
	_fs = false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(_renderer, w, h);
	_screen = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	_texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
	SDL_SetWindowTitle(_window, "You'd butter fly");
/*	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) == -1)
		throw(Exception("Cannot init SDL"));
	_fs = false;
		_screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_INIT_JOYSTICK);
	SDL_JoystickEventState(SDL_ENABLE);
	SDL_WM_SetCaption("You'd butter fly", NULL);*/
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
		SDL_SetWindowFullscreen(_window,SDL_WINDOW_FULLSCREEN);
	else
		SDL_SetWindowFullscreen(_window,0);
}

void	Graphics::printScreen()
{
	//SDL_Flip(_screen);
	//SDL_UpdateTexture(_texture, NULL, _screen->pixels, _screen->pitch); 
	//SDL_RenderClear(_renderer); 
	//SDL_RenderCopy(_renderer, _texture, NULL, NULL); 
	SDL_RenderPresent(_renderer);
}

void		Graphics::resetScreen(const Color &color)
{
	/*SDL_Rect	rect;

	rect.h = _h;
	rect.w = _maxX - _minX;
	rect.x = _minX;
	rect.y = 0;

	//SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, Uint32 color);
	SDL_FillRect(_screen, &rect, color.getInt());*/

	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
	SDL_RenderClear(_renderer);

}

void	Graphics::resetLocal(const Color &color)
{
	for (int j = 0; j < _screen->h; j++)
		for (int i = _minX; i < _maxX; i++)
			printPixelUnsafe(j, i, color.getInt());

}

void	Graphics::setCap(int min, int max)
{
	_minX = min;
	if (max == 0)
		_maxX = _screen->w;
	else
		_maxX = max;
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
	Position	pos2(pos1.y, pos3.x);
	Position	pos4(pos3.y, pos1.x);

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
	for (int i = pos1.x; i < pos3.x; i++)
		for (int j = pos1.y; j < pos3.y; j++)
			printPixel(Position(j, i), color);
}

/**********/
/* CIRCLE */
/**********/
void		Graphics::sponge(Position const &pos, float ray, int nb, float size, const Angle &angle, const Color &color)
{
	float		angleOffset = Math::maxRad / nb;
	float		goal = Math::maxRad + angle.rad();
	Position	pos1;
	Position	pos2;

	for (float i = angle.rad(); i < goal; i += angleOffset)
	{
		pos1 = Position(Angle(i), ray - size) + pos;
		pos2 = Position(Angle(i + angleOffset / 2), ray + size) + pos;
		line(pos1, pos2, color);
		pos1 = Position(Angle(i + angleOffset), ray - size) + pos;
		line(pos2, pos1, color);
	}
}

void		Graphics::circle(Position const &pos, float size, const Color &color)
{
	Position	pxPos;
	int		max = size * Math::maxRad;
	float		invSize = 1 / size;

	for (int i = 0; i < max; i++)
	{
		pxPos.x = size * Math::cos(i * invSize);
		pxPos.y = size * Math::sin(i * invSize);
		pxPos += pos;
		printPixel(pxPos, color);
	}
}

void		Graphics::circleFull(Position const &pos, float size, const Color &color)
{
	Position	pxPos;
	float		max = size * Math::maxRad;
	float		invSize = 1 / size;

	for (int i = 0; i < max; i++)
	{
		pxPos.x = size * Math::cos(i * invSize);
		pxPos.y = size * Math::sin(i * invSize);
		pxPos += pos;
		line(pxPos, pos, color);
	}
}

void		Graphics::circleLaid(Position const &pos, float size, const Color &color, const Color &color2)
{
	circle(pos, size - 1, color);
	circle(pos, size, color2);
	circle(pos, size + 1, color);
}

void		Graphics::circlePart(Position const &pos, float ray,
			const Angle &from, const Angle &size, const Color &color)
{
	Position	pxPos;
	int		max = ray * size.rad();
	float		invRay = 1 / ray;

	for (int i = 0; i < max; i ++)
		{
			pxPos.x = ray * Math::cos((i * invRay) + from.rad());
			pxPos.y = ray * Math::sin((i * invRay) + from.rad());
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
	int		range = vect.distance();

	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawLine(_renderer, pos1.x, pos1.y, pos2.x, pos2.y);

	/*for (int i = 0; i <= range; i++)
		printPixel(pos1 + Position(angle, i), color);*/
}

void		Graphics::line(Position const &pos1, Position const &pos2, const Color &color, int thick)
{
	/*
	if (pos1.x() == pos2.x() && pos1.y() == pos2.y())
		return ;
	*/
	//std::cout << pos1 << pos2 << " " << thick << std::endl;

	Position	vect = pos2 - pos1;
	Angle		angle = vect.angle();
	//Angle		angleOut[] = { vect.angle() + Angle(0, 0), vect.angle() + Angle(0, 0) };

	for (int j = 0; j < thick; j++)
	{
		float	val = j / 3.0;
		line(pos1 + Position(0, val) * angle + Position(val, 0) * angle,
				 pos2 + Position(0, val) * (angle + Angle(180, 0)) + (Position(val, 0) * angle), color);
	}
		/*
		line(pos1 + Position(0, j) * angle + (Position(j / 2, 0) * angleOut[j % 2]),
				 pos2 + Position(0, j) * (angle + Angle(180, 0)) + (Position(j / 2, 0) * angleOut[j % 2]), color);
	 */
}

void		Graphics::curveLine(Position const &pos1, Position const &pos2,
		Position const &pos3, const Color &color)
{
	line(pos1, pos2, color);
	line(pos2, pos3, color);
}

/*
void		Graphics::bend(Position const &pos1, float ray1,
	Position const &pos2, float ray2, const Color &color)
{
	curveLine(pos1, Circle(pos1, ray1) == Circle(pos2, ray2), pos2, color);
}*/

/*********/
/* PIXEL */
/*********/
void	Graphics::printPixel(Position const &pos, const Color &color)
{
	/*if (pos.x >= 0 && pos.x + _minX < _maxX && pos.y >= 0 && pos.y < _screen->h)
	{
		int	offset = static_cast<int> (pos.y) * _screen->pitch / 4 +
			static_cast<int> (pos.x) + _minX;
		*(static_cast<int *> (_screen->pixels) + offset) = color.getInt();
	}*/
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawLine(_renderer, pos.x, pos.y, pos.x + 1, pos.y + 1);
}

/*
void	Graphics::printPixelUnsafe(Position const &pos, const Color &color)
{
	*(static_cast<int *> (_screen->pixels) + pos.y() *
		_screen->pitch / 4 + pos.x()) = color.getInt();
}
*/
