//
// Inertie.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 11:20:17 2013 Brunier Jean
// Last update Fri Apr 12 12:23:00 2013 Brunier Jean
//

#ifndef INERTIE_HH_
# define INERTIE_HH_

# include "AAction.hh"

class Inertie : public PassiveAction
{
public:
  Inertie(Player &player);
  virtual ~Inertie();
  virtual bool		request();
};

#endif /* !INERTIE_HH_ */
