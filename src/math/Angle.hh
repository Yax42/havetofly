//
// Angle.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 09 17:07:10 2013 Brunier Jean
// Last update Sat Apr 13 17:00:03 2013 Brunier Jean
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
  Angle(int deg, int);

  /* OPERATORS */
  Angle		&operator+=(const Angle &other);
  Angle		&operator-=(const Angle &other);
  Angle		operator+(const Angle &other) const;
  Angle		operator-(const Angle &other) const;
  		operator Distance();

  void			deg(int v);
  int			deg() const;
  Distance		rad();
  Distance const	&rad() const;
};

#endif /* !ANGLE_HH_ */
