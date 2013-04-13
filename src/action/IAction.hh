//
// IAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 20:19:08 2013 Brunier Jean
// Last update Sat Apr 13 15:04:58 2013 Brunier Jean
//

#ifndef IACTION_HH_
# define IACTION_HH_

class IAction
{
  enum Action_e
    {
      GRAVITY,
      MOVE,
      DOUBLE_JUMP,
      DASH,
      MOON_DASH,
      BULL,
      RODEO,
      UP,
      COUNT
    };
  virtual ~IAction(){}
  virtual bool		allow(int a) = 0;
  virtual IAction	*step() = 0;
  virtual void		focus(Player &player) = 0;
  virtual bool		request() = 0;
  virtual void		init(int) = 0;
  virtual void		check() = 0;
  virtual int		val() = 0;
  virtual int		id() = 0;
  virtual const HitBox	&getHB() const = 0;
  virtual void		upBones() = 0;
};

#endif /* !IACTION_HH_ */
