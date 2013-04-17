//
// IAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 20:19:08 2013 Brunier Jean
// Last update Tue Apr 16 21:43:20 2013 Brunier Jean
//

#ifndef IACTION_HH_
# define IACTION_HH_

class Hitbox;
class Player;

class IAction
{
public:
  enum
    {
      INERTIE,
      GRAVITY,
      MOVE,
      DOUBLE_JUMP,
      HIT_WALL,
      STICK_CEILING,
      STICK_WALL,
      WALL_JUMP,
      COUNT,
      STUN,
      DASH,
      MOON_DASH,
      BULL,
      RODEO,
      UP
    };
  virtual ~IAction(){}
  virtual bool		allow(int a) = 0;
  virtual IAction	*step() = 0;
  //virtual void		focus(Player &player) = 0;
  virtual bool		request() = 0;
  virtual void		init(int v = 0) = 0;
  virtual void		hit(Player &ennemy) = 0;
  virtual void		check() = 0;
  virtual int		val() = 0;
  virtual int		id() = 0;
  virtual const Hitbox	&getHB() const = 0;
  virtual void		upBones() = 0;
};

#endif /* !IACTION_HH_ */
