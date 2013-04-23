//
// Shuriken.hh for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 23 11:09:09 2013 Brunier Jean
// Last update Tue Apr 23 12:01:13 2013 Brunier Jean
//

#ifndef SHURIKEN_HH_
# define SHURIKEN_HH_

# include "AThrowable.hh"

class Shuriken : public AThrowable
{
public:
  virtual ~Shuriken(){}
  Shuriken(const Player &player);
  virtual void		move();
  virtual void		print(Graphics &g) const;
};

#endif /* !SHURIKEN_HH_ */
