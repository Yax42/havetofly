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

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;
#else
    Uint32 rmask = 0x000000ff;
    Uint32 gmask = 0x0000ff00;
    Uint32 bmask = 0x00ff0000;
    Uint32 amask = 0xff000000;
#endif


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
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

Graphics::Graphics(int h, int w) : _h(h), _w(w), _minX(0), _maxX(w)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) == -1)
		throw(Exception("Cannot init SDL"));
	SDL_CreateWindowAndRenderer(w, h, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, &_window, &_renderer);
	if (!_window && !_renderer)
		throw(Exception("Cannot create window or renderer fail."));
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); 
	SDL_RenderClear(_renderer); 
	SDL_RenderPresent(_renderer);
	_fs = false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(_renderer, w, h);
	_screen = SDL_CreateRGBSurface(0, w, h, 32, 
                                        0, 
                                        0, 
                                        0, 
                                        0);
	SDL_SetWindowTitle(_window, "You'd butter fly");
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
	SDL_RenderPresent(_renderer);
}

void		Graphics::resetScreen(const Color &color)
{
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
	SDL_Rect rect;

	rect.x = pos1.x;
	rect.y = pos1.y;
	rect.w = pos3.x - pos1.x;
	rect.h = pos3.y - pos1.y;
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawRect(_renderer, &rect);
}

void		Graphics::rectangle(Position const &pos1, Position const &pos3, const Color &color)
{
	SDL_Rect rect;

	rect.x = pos1.x;
	rect.y = pos1.y;
	rect.w = pos3.x - pos1.x;
	rect.h = pos3.y - pos1.y;
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawRect(_renderer, &rect);
}

void		Graphics::rectangleLaid(Position const &pos1, Position const &pos3, const Color &color1, const Color &color2)
{
	rectangle(pos1 - 1, pos3 - 1, color1);
	rectangle(pos1, pos3, color2);
	rectangle(pos1 + 1, pos3 + 1, color1);
}

void		Graphics::rectangleFull(Position const &pos1, Position const &pos3, const Color &color)
{
	SDL_Rect rect;

	rect.x = pos1.x;
	rect.y = pos1.y;
	rect.w = pos3.x - pos1.x;
	rect.h = pos3.y - pos1.y;
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
	SDL_RenderFillRect(_renderer, &rect);
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
	SDL_Texture *texture;
	if ((texture = textureExist(ATexture::CIRCLE, size, &color)))
	{
		SDL_Rect SrcR;
		SDL_Rect DestR;

		SrcR.x = 0;
		SrcR.y = 0;
		SrcR.w = size*2;
		SrcR.h = size*2;

		DestR.x = pos.x - size;
		DestR.y = pos.y - size;
		DestR.w = size*2;
		DestR.h = size*2;
		SDL_RenderCopy(_renderer, texture, &SrcR, &DestR); 
	}
	else
	{
		Position	pxPos;
		int		max = size * Math::maxRad;
		float		invSize = 1 / size;
		SDL_Surface	*surface = SDL_CreateRGBSurface(0,size*2,size*2,32,0,0,0,0);
		surface->format->Amask = amask;
		surface->format->Ashift = 24;
		texture = SDL_CreateTexture(_renderer, 
                                            SDL_PIXELFORMAT_ARGB8888, 
                                            SDL_TEXTUREACCESS_STATIC, 
                                            size * 2, size * 2);
		Position	texPos(size, size);

		for (int i = 0; i < max; i++)
		{
			pxPos.x = size * Math::cos(i * invSize);
			pxPos.y = size * Math::sin(i * invSize);
			pxPos += texPos;
			printPixel(surface, pxPos, color);
		}
		Uint32 colorkey = SDL_MapRGB( surface->format, 0, 0, 0);
		int ret = SDL_SetColorKey(surface, SDL_TRUE, colorkey);
		texture = SDL_CreateTextureFromSurface(_renderer, surface);
		addTexture(ATexture::CIRCLE, texture, size, &color);
		SDL_FreeSurface(surface);
	}
}

void		Graphics::circleFull(Position const &pos, float size, const Color &color)
{
	SDL_Texture *texture;
	if ((texture = textureExist(ATexture::CIRCLEFULL, size, &color)))
	{
		SDL_Rect SrcR;
		SDL_Rect DestR;

		SrcR.x = 0;
		SrcR.y = 0;
		SrcR.w = size*2;
		SrcR.h = size*2;

		DestR.x = pos.x - size;
		DestR.y = pos.y - size;
		DestR.w = size*2;
		DestR.h = size*2;
		SDL_RenderCopy(_renderer, texture, &SrcR, &DestR); 
	}
	else
	{
		Position	pxPos;
		float		max = size * Math::maxRad;
		float		invSize = 1 / size;
		SDL_Surface	*surface = SDL_CreateRGBSurface(0,size*2, size*2,32,0,0,0,0);
				surface->format->Amask = amask;
		surface->format->Ashift = 24;
		SDL_Texture *texture = SDL_CreateTexture(_renderer, 
                                            SDL_PIXELFORMAT_ARGB8888, 
                                            SDL_TEXTUREACCESS_STATIC, 
                                            size * 2, size * 2);
		Position	texPos(size, size);

		for (int i = 0; i < max; i++)
		{
			pxPos.x = size * Math::cos(i * invSize);
			pxPos.y = size * Math::sin(i * invSize);
			pxPos += texPos;
			line(surface, pxPos, texPos, color);
		}
		Uint32 colorkey = SDL_MapRGB( surface->format, 0, 0, 0);
		SDL_SetColorKey(surface, SDL_TRUE, colorkey);
		SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch); 
		//texture = SDL_CreateTextureFromSurface(_renderer, surface);
		addTexture(ATexture::CIRCLEFULL, texture, size, &color);
		SDL_FreeSurface(surface);
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

void		Graphics::line(SDL_Surface *surface, Position const &pos1, Position const &pos2, const Color &color)
{
	Position	vect = pos2 - pos1;
	Angle		angle = vect.angle();
	int		range = vect.distance();

	for (int i = 0; i <= range; i++)
		printPixel(surface, pos1 + Position(angle, i), color);
}

void		Graphics::line(Position const &pos1, Position const &pos2, const Color &color)
{
	Position	vect = pos2 - pos1;
	Angle		angle = vect.angle();
	int		range = vect.distance();

	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawLine(_renderer, pos1.x, pos1.y, pos2.x, pos2.y);
}

void		Graphics::line(Position const &pos1, Position const &pos2, const Color &color, int thick)
{
	Position	vect = pos2 - pos1;
	Angle		angle = vect.angle();

	for (int j = 0; j < thick; j++)
	{
		float	val = j / 3.0;
		line(pos1 + Position(0, val) * angle + Position(val, 0) * angle,
				 pos2 + Position(0, val) * (angle + Angle(180, 0)) + (Position(val, 0) * angle), color);
	}
}

void		Graphics::curveLine(Position const &pos1, Position const &pos2,
		Position const &pos3, const Color &color)
{
	line(pos1, pos2, color);
	line(pos2, pos3, color);
}

/*********/
/* PIXEL */
/*********/
void	Graphics::printPixel(Position const &pos, const Color &color)
{
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawPoint(_renderer, pos.x, pos.y);
}

void	Graphics::printPixel(SDL_Surface *surface, Position const &pos, const Color &color)
{
	if (pos.x >= 0 && pos.x + _minX < _maxX && pos.y >= 0 && pos.y < surface->h)
	{
		int	offset = static_cast<int> (pos.y) * surface->pitch / 4 +
			static_cast<int> (pos.x) + _minX;
		*(static_cast<int *> (surface->pixels) + offset) = color.getInt();
	}
}

/**********/
/* TEXTURE*/
/**********/
void	Graphics::addTexture(ATexture::typetexture type, SDL_Texture* texture, float size, const Color* color)
{
	ATexture *newtexture = new ATexture(texture, color, size, type);

	_listTexture.push_back(newtexture);
}

SDL_Texture		*Graphics::textureExist(ATexture::typetexture type, float size, const Color* color) const
{
	for (std::vector<ATexture*>::const_iterator it = _listTexture.begin() ; it != _listTexture.end(); ++it)
	{
		if ((*it)->isSame(type, size, color))
			return ((*it)->getTexture());
	}
	return NULL;
}