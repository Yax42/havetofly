//
// Controler.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 18 17:34:29 2013 Brunier Jean
// Last update Thu Apr 18 20:55:56 2013 Brunier Jean
//

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>

#include "Exception.hh"
#include "Controler.hh"

Controler::~Controler()
{
  if (_fd != -1)
    close(_fd);
}

Controler::Controler(int id) : _id(id)
{
  _fd = -1;
  update();
}

bool	Controler::isOk() const
{
  return (_fd != -1 && _axe.size() >= 2 && _but.size() >= 6);
}

void	Controler::update()
{
  if (_fd != -1)
  {
    close(_fd);
    _axe.clear();
    _but.clear();
  }
  std::stringstream	stm;

  stm << "/dev/input/js" << _id;
    _fd = open(stm.str().c_str(), O_RDONLY | O_NONBLOCK);
  if (_fd == -1)
    return ;
  while (read(_fd, &_event, sizeof(_event)) > 0)
    {
      if (_event.type == 129)
	_but.push_back(0);
      if (_event.type == 130)
	_axe.push_back(0);
    }
}

Key	Controler::getKey()
{
  Key	k;

  //std::cout << _id << std::endl;
  if (!isOk())
    return (k);
  k.ptr(Key::HOR) = &_axe[0];
  k.ptr(Key::VERT) = &_axe[1];
  k.ptr(Key::A) = &_but[0];
  k.ptr(Key::B) = &_but[0];
  k.ptr(Key::X) = &_but[1];
  k.ptr(Key::Y) = &_but[2];
  k.ptr(Key::R) = &_but[3];
  k.ptr(Key::L) = &_but[4];
  return (k);
}

void	Controler::proc()
{
  if (_fd == -1)
    return ;
  while (read(_fd, &_event, sizeof(_event)) > 0)
    {
      if (_event.type == 1)
	_but[_event.number] = _event.value;
      if (_event.type == 2)
	_axe[_event.number] = _event.value;
    }
}
