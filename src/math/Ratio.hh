//
// Ratio.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 15 13:58:15 2013 Brunier Jean
// Last update Mon Apr 22 23:44:49 2013 Brunier Jean
//

#ifndef RATIO_HH_
# define RATIO_HH_

# include <iostream>

class Distance;

class Ratio
{
private:
  long		_val;

public:
  ~Ratio(){}
  Ratio();
  Ratio(int);
  Ratio(long);
  Ratio(long, int);
  Ratio(float);
  Ratio(double);
  Ratio(const Ratio &other);

  /* OPERATORS */
  Ratio		&operator+=(const Ratio &other);
  Ratio		&operator-=(const Ratio &other);
  Ratio		operator+(const Ratio &other) const;
  Ratio		operator-(const Ratio &other) const;

  Ratio		&operator%=(const Ratio &other);
  Ratio		operator%(const Ratio &other) const;

  Ratio		operator/(const Distance &v) const;
  Ratio		operator*(const Distance &v) const;
  Ratio		&operator/=(const Distance &v);
  Ratio		&operator*=(const Distance &v);

  bool			operator==(const Ratio &other) const;
  bool			operator!=(const Ratio &other) const;
  bool			operator<(const Ratio &other) const;
  bool			operator<=(const Ratio &other) const;
  bool			operator>(const Ratio &other) const;
  bool			operator>=(const Ratio &other) const;

  long			longVal() const;
  float			floatVal() const;
};

std::ostream	&operator<<(std::ostream &s, Ratio const &a);


#endif /* !RATIO_HH_ */
