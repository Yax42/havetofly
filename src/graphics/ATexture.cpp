#include "ATexture.hh"


ATexture::ATexture(SDL_Texture* texture, const Color* color, float size, typetexture type):_texture(texture), _color(color), _size(size), _type(type)
{
}


ATexture::~ATexture(void)
{
	SDL_DestroyTexture(_texture);
}

bool ATexture::isSame(typetexture type, float size, const Color *color) const
{
	if (_type == type && size == _size && color->r == _color->r && color->g == _color->g && color->b == _color->b)
		return (true);
	return (false);
}

SDL_Texture * ATexture::getTexture() const
{
	return (_texture);
}