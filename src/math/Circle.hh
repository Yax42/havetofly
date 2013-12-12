//
// Circle.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 15:58:58 2013 Brunier Jean
// Last update Sun Apr 14 16:03:43 2013 Brunier Jean
//

#ifndef CIRCLE_HH_
# define CIRCLE_HH_

# include "Position.hh"

class Circle
{
private:
  Position	_center;
  float		_ray;

public:
  ~Circle(){}
  Circle(const Position &center, float ray);
  Position	operator==(const Circle &other) const;
};

#endif /* !CIRCLE_HH_ */
