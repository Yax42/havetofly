//
// IThrowable.hh for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 23 02:52:56 2013 Brunier Jean
// Last update Tue Apr 23 11:31:22 2013 Brunier Jean
//

#ifndef ITHROWABLE_HH_
# define ITHROWABLE_HH_

class Player;
class Graphics;

class IThrowable
{
public:
  virtual ~IThrowable(){}
  virtual bool		isAlive() const = 0;
  virtual void		init() = 0;
  virtual void		proc() = 0;
  virtual void		move() = 0;
  virtual void		effect(const Player &p) = 0;
  virtual void		print(Graphics &g) const = 0;
  virtual void		printHB(Graphics &g) const = 0;
};

#endif /* !ITHROWABLE_HH_ */
