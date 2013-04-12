//
// Move.hh for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 23:59:27 2013 Brunier Jean
// Last update Fri Apr 12 12:22:47 2013 Brunier Jean
//

#ifndef MOVE_HH_
# define MOVE_HH_

# include "AAction.hh"

class Move : public PassiveAction
{
public:
  Move(Player &player);
  virtual ~Move();
  virtual bool		request();
};

#endif /* !MOVE_HH_ */
