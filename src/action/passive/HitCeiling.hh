//
// HitCeiling.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 22 00:24:42 2013 Brunier Jean
// Last update Mon Apr 22 00:26:12 2013 Brunier Jean
//

#ifndef HITCEILING_HH_
# define HITCEILING_HH_

# include "PassiveAction.hh"

class HitCeiling : public PassiveAction
{
public:
  HitCeiling(Player &player);
  virtual ~HitCeiling() {}
  virtual void		check();
};

#endif /* !HITCEILING_HH_ */
