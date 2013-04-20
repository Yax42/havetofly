//
// Tech.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:54:09 2013 Brunier Jean
// Last update Sat Apr 20 15:20:25 2013 Brunier Jean
//

#ifndef TECH_HH_
# define TECH_HH_

# include "PassiveAction.hh"

class Tech : public PassiveAction
{
public:
  Tech(Player &player);
  virtual ~Tech(){}
  virtual void		check();
  virtual int		val();
  virtual void		print(Graphics &g) const;
};

#endif /* !TECH_HH_ */
