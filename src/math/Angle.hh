//
// Angle.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 09 17:07:10 2013 Brunier Jean
// Last update Fri Apr 12 16:42:54 2013 Brunier Jean
//

#ifndef ANGLE_HH_
# define ANGLE_HH_

# include "Distance.hh"

class	Angle
{
private:
  Distance	_rad;

public:
  Angle();
  Angle(Distance const & d);
  Angle(int v);
  Angle		&operator+=(const Angle &other);
  Angle		&operator-=(const Angle &other);
  Angle		&operator+=(int other);
  Angle		&operator-=(int other);
  Angle		&operator=(int other);
  Angle		&operator+=(float other);
  Angle		&operator-=(float other);
  Angle		&operator=(float other);

  Angle		operator+(const Angle &other) const;
  Angle		operator-(const Angle &other) const;
  Angle		operator+(int other) const;
  Angle		operator-(int other) const;
  Angle		operator+(float other) const;
  Angle		operator-(float other) const;

  int		deg() const;
  float		rad() const;
  Distance	dist() const;
  long		longVal() const;
};

#endif /* !ANGLE_HH_ */
