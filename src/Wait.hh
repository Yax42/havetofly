//
// Wait.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:00:39 2013 Brunier Jean
// Last update Sun Apr 14 01:10:14 2013 Brunier Jean
//

#ifndef WAIT_HH_
# define WAIT_HH_

# include <sys/timeb.h>

class Wait
{
private:
  timeb			_t1;
  timeb			_t2;
  int			_mspi;

public:
  ~Wait(){}
  Wait(int fps);
  void		proc();
};

#endif /* !WAIT_HH_ */
