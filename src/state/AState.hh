//
// AState.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 16:39:21 2013 Brunier Jean
// Last update Wed Apr 10 17:07:58 2013 Brunier Jean
//

#ifndef ASTATE_HH_
# define ASTATE_HH_

# include "IState.hh"
# include "Bones.hh"

class AState : public IState
{
private:
  Hitbox	_hb;
  Bones		&_bones;

public:
  Astate(Bones &b, const Position &topL, const Position &botR, const Position &center);
  virtual ~AState();
  virtual bool	touch(const Hitbox &other) const;
  virtual void	updateBones();
};


#endif /* !ASTATE_HH_ */
