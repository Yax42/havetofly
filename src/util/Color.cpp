//
// Color.cpp for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Mon Apr 22 18:01:03 2013 Brunier Jean
// Last update Sun May 05 22:30:16 2013 Brunier Jean
//

#include "Color.hh"

const Color	Color::RED = Color(255, 0, 0);
const Color	Color::YELLOW = Color(255, 255, 0);
const Color	Color::GREEN = Color(0, 255, 0);
const Color	Color::BLUE = Color(0, 0, 255);
const Color	Color::WHITE = Color(255, 255, 255);
const Color	Color::BLACK = Color(0, 0, 0);

const Color	Color::fire[4] =
		{
			0xFF0000,
			0xFF4400,
			0xFFFF00,
			0xFF9900
		};

Color::Color(int col) : r((col >> 16) & 0xFF), g((col >> 8) & 0xFF), b(col & 0xFF)
{
}

Color::Color(int red, int green, int blue) : r(red), g(green), b(blue)
{
}

Color		&Color::operator-=(Color const &col)
{
	r -= col.r;
	if (r < 0)
		r = 0;
	g -= col.g;
	if (g < 0)
		g = 0;
	b -= col.b;
	if (b < 0)
		b = 0;
	return (*this);
}

Color		&Color::operator+=(Color const &col)
{
	r += col.r;
	if (r > 0xFF)
		r = 0xFF;
	g += col.g;
	if (g > 0xFF)
		g = 0xFF;
	b += col.b;
	if (b > 0xFF)
		b = 0xFF;
	return (*this);
}

Color		Color::operator-(Color const &col) const
{
	Color		ret(*this);

	ret.r -= col.r;
	if (ret.r < 0)
		ret.r = 0;
	ret.g -= col.g;
	if (ret.g < 0)
		ret.g = 0;
	ret.b -= col.b;
	if (ret.b < 0)
		ret.b = 0;
	return (ret);
}

Color		Color::operator-(int col) const
{
	Color		ret(*this);

	ret.r -= col;
	if (ret.r < 0)
		ret.r = 0;
	ret.g -= col;
	if (ret.g < 0)
		ret.g = 0;
	ret.b -= col;
	if (ret.b < 0)
		ret.b = 0;
	return (ret);
}

Color		Color::operator+(Color const &col) const
{
	Color		ret(*this);

	ret.r += col.r;
	if (ret.r > 0xFF)
		ret.r = 0xFF;
	ret.g += col.g;
	if (ret.g > 0xFF)
		ret.g = 0xFF;
	ret.b += col.b;
	if (ret.b > 0xFF)
		ret.b = 0xFF;
	return (ret);
}

Color		Color::operator/(int v) const
{
	return (Color(r / v, g / v, b / v));
}

Color		Color::operator*(int v) const
{
	Color		ret(*this);

	ret.r *= v;
	if (ret.r > 255)
		ret.r = 255;
	ret.g *= v;
	if (ret.g > 255)
		ret.g = 255;
	ret.b *= v;
	if (ret.b > 255)
		ret.b = 255;
	return (ret);
}

int		Color::getInt() const
{
	return ((r << 16) + (g << 8) + b);
}
