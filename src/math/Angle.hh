//
// Angle.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 09 17:07:10 2013 Brunier Jean
// Last update Tue Apr 23 14:31:11 2013 Brunier Jean
//

#ifndef ANGLE_HH_
# define ANGLE_HH_

#include <iostream>

class	Angle
{
private:
	float		_rad;

public:
	~Angle(){}
	Angle();
	Angle(float d);
	Angle(float deg, int);

	/* OPERATORS */
	Angle		betweenX(Angle const &a, int sign) const;
	Angle		mirrorX() const;
	Angle		mirrorY() const;
	Angle		operator+(Angle const &a) const;
	Angle		&operator+=(Angle const &a);
	Angle		operator-(Angle const &a) const;
	Angle		&operator-=(Angle const &a);
			//operator float() const;

	/* ACCESS */
	void			deg(float v);
	float			deg() const;
	void			rad(float v);
	float			rad() const;
};

std::ostream	&operator<<(std::ostream &s, Angle const &a);

#endif /* !ANGLE_HH_ */
