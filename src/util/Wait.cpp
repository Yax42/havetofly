//
// Wait.cpp for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:03:17 2013 Brunier Jean
// Last update Fri Apr 19 22:27:55 2013 Brunier Jean
//

#include <unistd.h>
#include <iostream>

#include "Wait.hh"

Wait::Wait(int fps) : _fps(fps), _uspi(1000000 / fps), _nbFrames(0)
{
  gettimeofday(&_t1, NULL);
}

void		Wait::proc()
{
  int		time;

  gettimeofday(&_t2, NULL);
  time = _uspi - (_t2.tv_sec - _t1.tv_sec) * 1000000 +
    (_t2.tv_usec - _t1.tv_usec);
  if (time > 0)
    usleep(time);
  gettimeofday(&_t1, NULL);
}
