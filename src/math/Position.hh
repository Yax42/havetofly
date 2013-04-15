/*
** Position.hh for src in /home/brunie_j/local/nibbler/nibbler/src
**
** Made by Brunier Jean
** Login   <brunie_j@epitech.net>
**
** Started on  Tue Mar 05 17:03:25 2013 Brunier Jean
** Last update Wed Mar 20 10:43:57 2013 Brunier Jean
*/

#ifndef POSITION_HH_
# define POSITION_HH_

# include <cstdlib>
# include <iostream>

# include "Distance.hh"
# include "Angle.hh"

class Position
{
  Distance	_y;
  Distance	_x;

public:
  /* CONSTRUCTORS */
  ~Position();
  Position();
  Position(const Distance &y, const Distance &x);
  Position(const Angle &angle, const Distance &distance);
  Position(const Distance &y, const Distance &x, int);
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

  Position		operator+(const Distance &v) const;
  Position		operator-(const Distance &v) const;
  Position		operator*(const Distance &v) const;
  Position		operator/(const Distance &v) const;
  Position		&operator+=(const Distance &v);
  Position		&operator-=(const Distance &v);
  Position		&operator*=(const Distance &v);
  Position		&operator/=(const Distance &v);

  /* ROTATION */
  Position		operator*(const Angle& angle) const;
  Position		&operator*=(const Angle& angle);
  Position		&rotate(const Angle &angle, Position const &center);

  /* GETTERS */
  int			x() const;
  int			y() const;
  void			x(Distance const &x);
  void			y(Distance const &y);
  Distance		&xDist();
  Distance		&yDist();
  const Distance	&xDist() const;
  const Distance	&yDist() const;

  Angle			angle() const;
  Distance		distance() const;
};

std::ostream	&operator<<(std::ostream &s, Position const &pos);

#endif /* !POSITION_HH_ */
