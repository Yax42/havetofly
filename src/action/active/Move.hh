//
// Move.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 23:59:27 2013 Brunier Jean
// Last update Sun Apr 14 18:13:51 2013 Brunier Jean
//

#ifndef MOVE_HH_
# define MOVE_HH_

# include "PassiveAction.hh"

class Move : public PassiveAction
{
public:
  Move(Player &player);
  virtual ~Move(){}
  virtual bool		request();
  virtual int		id();
};

#endif /* !MOVE_HH_ */
