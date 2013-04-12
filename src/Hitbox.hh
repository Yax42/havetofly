//
// Hitbox.hh for geometry in /home/brunie_j/local/my/havetofly/src/geometry
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 15:39:05 2013 Brunier Jean
// Last update Wed Apr 10 15:50:36 2013 Brunier Jean
//

#ifndef HITBOX_HH_
# define HITBOX_HH_

# include "Position.hh"

class Hitbox
{
private:
  Position		_topL;
  Position		_botR;
  const Position	&_center;

public:
  Hitbox(const Position &topL, const Position &botR, const Position &center);
  ~Hitbox();
  bool		touch(const Hitbox &other) const;
};

#endif /* !HITBOX_HH_ */
