//
// JeanCtrl.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 01:11:28 2013 Brunier Jean
// Last update Wed Apr 17 11:25:37 2013 Brunier Jean
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
    {
      _trueK[i] = 0;
      _fakeK[i] = 0;
    }
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
    k.ptr(i) = &_fakeK[i];
  return (k);
}

void	JeanCtrl::setVal(int idx, bool val)
{
  if (_trueK[idx] == val)
    return ;
  _trueK[idx] = val;
  _fakeK[idx] = val;
}

void	JeanCtrl::proc()
{
  if (_fd == -1)
    return ;
  int	nbChar;
  while ((nbChar = read(_fd, _buf, 30)) > 0)
    {
      _fakeK[0] = (_buf[0] * 1000) / 128;
      _fakeK[1] = (_buf[1] * 1000) / 128;
      setVal(Key::A, (_buf[4] & 16) != 0);
      setVal(Key::B, (_buf[4] & 64) != 0);
      setVal(Key::X, (_buf[4] & 128) != 0);
      setVal(Key::Y, (_buf[4] & 32) != 0);
      setVal(Key::R, (_buf[5] & 8) != 0);
      setVal(Key::L, (_buf[5] & 2) != 0);
    }
}
