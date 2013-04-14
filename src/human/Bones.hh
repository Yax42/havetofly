//
// Bones.hh for human in /home/brunie_j/local/my/havetofly/src/human
// // Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 16:06:02 2013 Brunier Jean
// Last update Sun Apr 14 15:33:46 2013 Brunier Jean
//

#ifndef BONES_HH_
# define BONES_HH_

# include "Position.hh"

class Graphics;

class Bones
{
private:
  const Position	&_center;
  const int		&_orient;
  int			_color;
  int			_color2;
private:
  Position		_foot1;
  Position		_foot2;
  Position		_hand1;
  Position		_hand2;
  Distance		_back;
  Angle			_angle;
  Angle			_head;
public:
  Position		foot1;
  Position		foot2;
  Position		hand1;
  Position		hand2;
  Distance		back;
  Angle			angle;
  Angle			head;

public:
  Bones(const Position &centre, int color, int color2, const int &orient);
  ~Bones();
  void		print(Graphics &g) const;
private:
  void		up(Position const &old, Position &next, int max);
  void		check();
};

#endif /* !BONES_HH_ */
