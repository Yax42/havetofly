//
// Distance.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 09:20:03 2013 Brunier Jean
// Last update Fri Apr 12 16:32:03 2013 Brunier Jean
//

#ifndef DISTANCE_HH_
# define DISTANCE_HH_

class Distance
{
private:
  long		_val;

public:
  Distance();
  Distance(float v);
  Distance(int v);
  Distance(long v);

  Distance		&operator+=(const Distance &other);
  Distance		&operator-=(const Distance &other);
  Distance		&operator*=(const Distance &other);
  Distance		&operator/=(const Distance &other);

  Distance		operator+(const Distance &other) const;
  Distance		operator-(const Distance &other) const;
  Distance		operator*(const Distance &other) const;
  Distance		operator/(const Distance &other) const;

  /*
  operator int() const;
  operator long() const;
  operator float() const;
  */

  long			longVal() const;
  int			intVal() const;
  float			floatVal() const;
};

#endif /* !DISTANCE_HH_ */
