//
// Bones.hh for human in /home/brunie_j/local/my/havetofly/src/human
// // Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 16:06:02 2013 Brunier Jean
// Last update Sun Apr 14 21:59:29 2013 Brunier Jean
//

#ifndef BONES_HH_
# define BONES_HH_

# include "Position.hh"

class Graphics;

class Bones
{
public:
  enum
    {
      FOOT1,
      KNEE1,
      HAND1,
      ELBOW1,
      FOOT2,
      KNEE2,
      HAND2,
      ELBOW2,
      HEAD,
      BODY,
      COUNT
    };

private:
  const Position	&_center;
  const int		&_orient;
  int			_color;
  int			_color2;
private:
  static const int	_size[Bones::COUNT];
private:
  Angle			_angle[Bones::COUNT];
public:
  Angle			angle[Bones::COUNT];
public:
  Bones(const Position &centre, int color, int color2, const int &orient);
  ~Bones();
  void		print(Graphics &g);
private:
  void		up(Position const &old, Position &next, int max);
  void		check();
};

#endif /* !BONES_HH_ */
