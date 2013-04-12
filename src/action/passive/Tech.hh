//
// Tech.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:54:09 2013 Brunier Jean
// Last update Fri Apr 12 12:24:28 2013 Brunier Jean
//

#ifndef TECH_HH_
# define TECH_HH_

# include "AAction.hh"

class Tech : public AAction
{
public:
  Tech(Player &player);
  virtual ~Tech();
  virtual void		check();
  virtual int		val();
};

#endif /* !TECH_HH_ */
