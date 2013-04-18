//
// Bones.hh for human in /home/brunie_j/local/my/havetofly/src/human
// // Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 16:06:02 2013 Brunier Jean
// Last update Thu Apr 18 01:39:45 2013 Brunier Jean
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
  Position		_pos[Bones::COUNT];
  Angle			_angle[Bones::COUNT];
public:
  Angle			angle[Bones::COUNT];
public:
  Bones(const Position &centre, int color, int color2, const int &orient);
  ~Bones();
  void			print(Graphics &g);
  const Position	&operator[](int id) const;
private:
  void			check();
};

#endif /* !BONES_HH_ */
