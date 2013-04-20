//
// IAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 20:19:08 2013 Brunier Jean
// Last update Sat Apr 20 19:55:29 2013 Brunier Jean
//

#ifndef IACTION_HH_
# define IACTION_HH_

# include <list>

class Hitbox;
class Player;
class Bones;
class Graphics;

class IAction
{
public:
  enum
    {
      INERTIE,
      GRAVITY,
      HIT_WALL,
      DEATH,
/* */ MOVE, /* ACTIVE STARTS HERE */
      DOUBLE_JUMP,
      TECH,
      SHIELD,
      SPIN,
      HOR_DASH,
      STICK_CEILING,
      STICK_WALL,
      UP_PUNCH,
      WALL_JUMP,
      DOWN_DASH,
      STUN,
/* */ COUNT, /* End of the list */
      MOON_DASH,
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
  virtual void		set(int val = 0) = 0;
  virtual int		id() const = 0;
  virtual bool		isActive() const = 0;
  virtual const	std::list<Hitbox>	&getHB() const = 0;
  virtual void		upBones() = 0;
  virtual void		print(Graphics &g) const = 0;
  virtual void		printHB(Graphics &g) const = 0;
};

#endif /* !IACTION_HH_ */
