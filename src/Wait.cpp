//
// Wait.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:03:17 2013 Brunier Jean
// Last update Sun Apr 14 01:13:02 2013 Brunier Jean
//

#include "Wait.hh"
#include <unistd.h>

Wait::Wait(int fps) : _mspi(1000 / fps)
{
  ftime(&_t1);
}

void		Wait::proc()
{
  int		time;

  ftime(&_t2);
  time = (_t2.time - _t1.time) * 1000 + (_t2.millitm - _t1.millitm);
  time = _mspi - time;
  if (time > 0)
    usleep(time * 1000);
  ftime(&_t1);
}
