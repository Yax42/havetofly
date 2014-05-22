#pragma once
#ifndef ATEXTURE_HH__
#define ATEXTURE_HH__

#include <SDL2\SDL.h>
#include "Color.hh"

class ATexture
{
public:
	typedef enum e_typetexture
	{
		CIRCLE,
		CIRCLEFULL,
		CIRCLEPART
	} typetexture;
protected:
	SDL_Texture			*_texture;
	const Color			*_color;
	float				_size;
	typetexture			_type;
public:
	ATexture(SDL_Texture*, const Color*, float, typetexture);
	virtual ~ATexture(void);

	bool			isSame(typetexture, float, const Color*) const;
	SDL_Texture*	getTexture() const;
};

#endif /* ATEXTURE_HH__ */