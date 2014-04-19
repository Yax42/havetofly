/*
** Position.hh for src in /home/brunie_j/local/nibbler/nibbler/src
**
** Made by Brunier Jean
** Login	 <brunie_j@epitech.net>
**
** Started on	Tue Mar 05 17:03:25 2013 Brunier Jean
** Last update Wed Mar 20 10:43:57 2013 Brunier Jean
*/

#ifndef POSITION_HH_
# define POSITION_HH_

# include <cstdlib>
# include <iostream>

# include "Angle.hh"

class Position
{
public:
	float	y;
	float	x;

public:
	/* CONSTRUCTORS */
	~Position();
	Position();
	Position(float v);
	Position(float y, float x);
	Position(const Angle &angle, float d);
	Position(Position const &other);
	Position		&operator=(Position const &other);

	/* COMPARISONS */
	bool			operator==(Position const &other) const;
	bool			operator!=(Position const &other) const;

	/* POSITION OPERATIONS */
	Position		&operator+=(Position const &other);
	Position		&operator-=(Position const &other);
	Position		operator+(Position const &other) const;
	Position		operator-(Position const &other) const;
	//Position		&operator*=(Position const &other);
	//Position		&operator/=(Position const &other);
	//Position		operator*(Position const &other) const;
	//Position		operator/(Position const &other) const;

	/* INT OPERATIONS */

	//Position		&operator/=(Position const &other);
	//Position		operator/(Position const &other) const;

	Position		operator+(float v) const;
	Position		operator-(float v) const;
	Position		operator*(float v) const;
	Position		operator/(float v) const;
	Position		&operator+=(float v);
	Position		&operator-=(float v);
	Position		&operator*=(float v);
	Position		&operator/=(float v);

	/* ROTATION */
	Position		operator*(const Angle& angle) const;
	Position		&operator*=(const Angle& angle);
	Position		&rotate(const Angle &angle, Position const &center);
	Position		switchX(bool isOk) const;

	/* GETTERS */

	Angle			angle() const;
	float			distance() const;
	float			distance(const Position &other) const;
	float			squaredDistance() const;
	float			squaredDistance(const Position &other) const;


	float		dot(const Position &other);
	Position	normalize() const;
	void		normalized();

	static const Position	UnitX;
	static const Position	UnitY;
};

std::ostream	&operator<<(std::ostream &s, Position const &pos);

#endif /* !POSITION_HH_ */
