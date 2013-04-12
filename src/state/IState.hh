//
// IState.hh for state in /home/brunie_j/local/my/havetofly/src/state
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 15:52:46 2013 Brunier Jean
// Last update Wed Apr 10 16:40:13 2013 Brunier Jean
//

#ifndef ISTATE_HH_
# define ISTATE_HH_

# include "Hitbox.hh"

class IState
{
  virtual bool	touch(const Hitbox &other) const = 0;
  virtual void	updateBones() = 0;
  virtual ~IState();
};

#endif /* !ISTATE_HH_ */
