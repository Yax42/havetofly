//
// RatioPosition.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 22 23:17:11 2013 Brunier Jean
// Last update Tue Apr 23 01:29:15 2013 Brunier Jean
//

#ifndef RATIOPOSITION_HH_
# define RATIOPOSITION_HH_

# include <cstdlib>
# include <iostream>

# include "Ratio.hh"
# include "Angle.hh"
# include "Distance.hh"
# include "Position.hh"

class Position;

class RatioPosition
{
  Ratio	_y;
  Ratio	_x;

public:
  /* CONSTRUCTORS */
  ~RatioPosition();
  RatioPosition();
  RatioPosition(const Position &pos);
  RatioPosition(const Ratio &y, const Ratio &x);
  RatioPosition(const Angle &angle, const Distance &distance);
  RatioPosition(const Ratio &y, const Ratio &x, int);
  RatioPosition(RatioPosition const &other);
  RatioPosition		&operator=(RatioPosition const &other);

  /* COMPARISONS */
  bool			operator==(RatioPosition const &other) const;
  bool			operator!=(RatioPosition const &other) const;

  /* POSITION OPERATIONS */
  RatioPosition		&operator+=(RatioPosition const &other);
  RatioPosition		&operator-=(RatioPosition const &other);
  RatioPosition		operator+(RatioPosition const &other) const;
  RatioPosition		operator-(RatioPosition const &other) const;

  /* INT OPERATIONS */

  //RatioPosition		&operator/=(RatioPosition const &other);
  //RatioPosition		operator/(RatioPosition const &other) const;

  RatioPosition		operator+(const Ratio &v) const;
  RatioPosition		operator-(const Ratio &v) const;
  RatioPosition		operator*(const Distance &v) const;
  RatioPosition		operator/(const Distance &v) const;
  RatioPosition		&operator+=(const Ratio &v);
  RatioPosition		&operator-=(const Ratio &v);
  RatioPosition		&operator*=(const Distance &v);
  RatioPosition		&operator/=(const Distance &v);

  /* ROTATION */
  RatioPosition		operator*(const Angle& angle) const;
  RatioPosition		&operator*=(const Angle& angle);
  RatioPosition		&rotate(const Angle &angle, RatioPosition const &center);

  /* GETTERS */
  int			x() const;
  int			y() const;
  RatioPosition		&x(Ratio const &x);
  RatioPosition		&y(Ratio const &y);
  Distance		xDist() const;
  Distance		yDist() const;
  const Ratio		&xRatio() const;
  const Ratio		&yRatio() const;

  Angle			angle() const;
  Distance		distance() const;
  //operator Position();
};

std::ostream	&operator<<(std::ostream &s, RatioPosition const &pos);

#endif /* !RATIOPOSITION_HH_ */
