//
// Angle.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 09 17:07:10 2013 Brunier Jean
// Last update Tue Apr 16 18:04:33 2013 Brunier Jean
//

#ifndef ANGLE_HH_
# define ANGLE_HH_

# include "Ratio.hh"

class	Angle
{
private:
  Ratio		_rad;

public:
  ~Angle(){}
  Angle();
  Angle(Ratio const & d);
  Angle(int deg, int);

  /* OPERATORS */
  Angle		&operator+=(const Angle &other);
  Angle		&operator-=(const Angle &other);
  Angle		operator+(const Angle &other) const;
  Angle		operator-(const Angle &other) const;
  		operator Ratio() const;
  Angle		mirrorX() const;
  Angle		mirrorY() const;


  void			deg(int v);
  int			deg() const;
  Ratio			rad();
  Ratio const		&rad() const;
};

std::ostream	&operator<<(std::ostream &s, Angle const &a);

#endif /* !ANGLE_HH_ */
