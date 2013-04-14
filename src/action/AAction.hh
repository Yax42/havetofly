//
// AAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 20:27:41 2013 Brunier Jean
// Last update Sat Apr 13 20:42:43 2013 Brunier Jean
//

#ifndef AACTION_HH_
# define AACTION_HH_

# include "IAction.hh"

class Hit;
class Player;

class AAction : public IAction
{
protected:
  Player	&_player;
  Hit		*_hit;
  int		_busy;
  int		_count;

public:
  virtual ~AAction();
  AAction(Player &player, Hit *hit);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual void		hit(Player *ennemy);
  virtual int		val();
  virtual bool		request() = 0;
  virtual void		check() = 0;
  virtual const HitBox	&getHB() const = 0;
  virtual void		upBones() = 0;
};


#endif /* !AACTION_HH_ */
