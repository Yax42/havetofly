//
// Move.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 23:59:27 2013 Brunier Jean
// Last update Fri Apr 19 13:55:22 2013 Brunier Jean
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
};

#endif /* !MOVE_HH_ */
