//
// Hitbox.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 15:39:05 2013 Brunier Jean
// Last update Fri Apr 12 22:39:16 2013 Brunier Jean
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
