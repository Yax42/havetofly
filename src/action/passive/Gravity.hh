//
// Gravity.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:07:11 2013 Brunier Jean
// Last update Sun Apr 14 17:46:40 2013 Brunier Jean
//

#ifndef GRAVITY_HH_
# define GRAVITY_HH_

# include "PassiveAction.hh"

class Gravity : public PassiveAction
{
public:
  Gravity(Player &player);
  virtual ~Gravity(){}
  virtual bool		request();
  virtual int		id();
};

#endif /* !GRAVITY_HH_ */
