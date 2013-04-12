//
// IAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 20:19:08 2013 Brunier Jean
// Last update Fri Apr 12 11:19:45 2013 Brunier Jean
//

#ifndef IACTION_HH_
# define IACTION_HH_

class IAction
{
  enum Action
    {
      A_FALL,
      A_MOVE,
      A_DOUBLE_JUMP,
      A_DASH,
      A_MOON_DASH,
      A_BULL,
      A_RODEO,
      A_UP,
      A_COUNT
    };
  virtual ~IAction();
  virtual int		init() = 0;
  virtual bool		allow(int a) = 0;
  virtual IAction	*step() = 0;
  virtual void		hit(Player &player) = 0;
  virtual bool		request() = 0;
  virtual void		check() = 0;
  virtual int		val() = 0;
};

#endif /* !IACTION_HH_ */
