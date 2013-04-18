//
// JeanCtrl.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 01:11:28 2013 Brunier Jean
// Last update Thu Apr 18 17:46:06 2013 Brunier Jean
//

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

#include "Exception.hh"
#include "JeanCtrl.hh"

JeanCtrl::JeanCtrl()
{
  _fd = -1;
  update();
  for (int i = 0; i < 0; i++)
    _keys[i] = 0;
}

JeanCtrl::~JeanCtrl()
{
  if (_fd != -1)
    close(_fd);
}

bool	JeanCtrl::isOk() const
{
  return (_fd != -1);
}

void	JeanCtrl::update()
{
  if (_fd == -1)
    _fd = open("/dev/hidraw1", O_RDONLY | O_NONBLOCK);
}

Key	JeanCtrl::getKey()
{
  Key	k;

  for (int i = 0; i < Key::COUNT; i++)
    k.ptr(i) = &_keys[i];
  return (k);
}

void	JeanCtrl::proc()
{
  if (_fd == -1)
    return ;
  int	nbChar;
  while ((nbChar = read(_fd, _buf, 30)) > 0)
    {
      _keys[Key::HOR] = (_buf[0] * 1000) / 128;
      _keys[Key::VERT] = (_buf[1] * 1000) / 128;
      _keys[Key::B] = (_buf[4] & 16) != 0;
      _keys[Key::A] = (_buf[4] & 64) != 0;
      _keys[Key::X] = (_buf[4] & 128) != 0;
      _keys[Key::Y] = (_buf[4] & 32) != 0;
      _keys[Key::R] = (_buf[5] & 8) != 0;
      _keys[Key::L] =  (_buf[5] & 2) != 0;
    }
}
