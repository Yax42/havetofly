/*
** Position.cpp for src in /home/brunie_j/local/nibbler/nibbler/src
**
** Made by Brunier Jean
** Login	 <brunie_j@epitech.net>
**
** Started on	Tue Mar 05 17:12:19 2013 Brunier Jean
** Last update Sun Mar 17 12:18:44 2013 Brunier Jean
*/

#include "Position.hh"
#include "Math.hh"

/****************/
/* CONSTRUCTORS */
/****************/

Position::~Position(){}

Position::Position()
{
	y = 0;
	x = 0;
}

Position::Position(float Y, float X) : y(Y), x(X)
{
}

Position::Position(Angle const &angle, float d)
{
	y = d * Math::sin(angle);
	x = d * Math::cos(angle);
}

Position::Position(Position const &other) : y(other.y), x(other.x)
{
}

Position	&Position::operator=(Position const &other)
{
	y = other.y;
	x = other.x;
	return (*this);
}

/****************/
/* COMPARAISONS */
/****************/

bool		Position::operator==(Position const &other) const
{
	return (x == other.x && y == other.y);
}

bool		Position::operator!=(Position const &other) const
{
	return (!operator==(other));
}

/***********************/
/* POSITION OPERATIONS */
/***********************/

Position	&Position::operator+=(Position const &other)
{
	y += other.y;
	x += other.x;
	return (*this);
}

Position	&Position::operator-=(Position const &other)
{
	y -= other.y;
	x -= other.x;
	return (*this);
}

Position	Position::operator+(Position const &other) const
{
	return (Position(y + other.y, x + other.x));
}

Position	Position::operator-(Position const &other) const
{
	return (Position(y - other.y, x - other.x));
}

/*
Position	&Position::operator*=(Position const &other)
{
	y *= other.y;
	x *= other.x;
	return (*this);
}

Position	&Position::operator/=(Position const &other)
{
	y /= other.y;
	x /= other.x;
	return (*this);
}

Position	Position::operator*(Position const &other) const
{
	return (Position(y * other.y, x * other.x, 0));
}

Position	Position::operator/(Position const &other) const
{
	return (Position(y / other.y, x / other.x, 0));
}
*/

/***********************/
/* DISTANCE OPERATIONS */
/***********************/
Position	Position::operator+(float v) const
{
	return (Position(y + v, x + v));
}

Position	Position::operator-(float v) const
{
	return (Position(y - v, x - v));
}


Position	&Position::operator+=(float v)
{
	x += v;
	y += v;
	return (*this);
}

Position	&Position::operator-=(float v)
{

	x -= v;
	y -= v;
	return (*this);
}

/////
Position	Position::operator*(float v) const
{
	return (Position(y * v, x * v));
}

Position	Position::operator/(float v) const
{
	Position	tmp(y, x);

	tmp.y /= v;
	tmp.x /= v;
	return (tmp);
}

Position	&Position::operator*=(float v)
{
	x *= v;
	y *= v;
	return (*this);
}

Position	&Position::operator/=(float v)
{

	x /= v;
	y /= v;
	return (*this);
}

/************/
/* ROTATION */
/************/

Position		Position::operator*(const Angle& a) const
{
	return (Position(a + angle(), distance()));
}

Position		&Position::operator*=(const Angle& angle)
{
	float		d = distance();
	Angle		a(angle + this->angle());

	x = (d * Math::cos(a));
	y = (d * Math::sin(a));
	return (*this);
}

Position		&Position::rotate(const Angle &a, Position const &center)
{
	Position	origin(*this - center);
	Position	next(Position(origin.angle() + a, origin.distance()) + center);

	x = next.x;
	y = next.y;
	return (*this);
}

Position	Position::switchX(bool isOk) const
{
	if (!isOk)
		return (*this);
	return (Position(y, -x));

}
/***********/
/* GETTERS */
/***********/

float	Position::squaredDistance() const
{
	return (x * x + y * y);
}

float	Position::squaredDistance(const Position &other) const
{
	return ((*this - other).squaredDistance());
}

float	Position::distance() const
{
	return (Math::sqrt(x * x + y * y));
}

float	Position::distance(const Position &other) const
{
	return ((*this - other).distance());
}

Angle		Position::angle() const
{
	if (distance() == 0)
		return (0);
	return (Angle(Math::acos(x / distance()) * ((y >= 0) - (y < 0))));
}

std::ostream	&operator<<(std::ostream &s, Position const &pos)
{
	std::cout.setf( std::ios::fixed, std::ios::floatfield ); 
	std::cout.precision(1);
	s << "[" << pos.y << ", " << pos.x << "]";
	return (s);
}
