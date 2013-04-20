//
// Controler.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 18 17:34:29 2013 Brunier Jean
// Last update Sat Apr 20 21:30:36 2013 Brunier Jean
//

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>

#include "MyTime.hh"
#include "Exception.hh"
#include "Controler.hh"

#define STICK_TO_SPEED(x)	(x >> 5)

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
    close(_fd);
  std::stringstream	stm;
  stm << "/dev/input/js" << _id;
    _fd = open(stm.str().c_str(), O_RDONLY | O_NONBLOCK);
  //std::cout << MTIME << " " <<  _id << " " << stm.str() << std::endl;
  if (_fd == -1)
    {
      _axe.clear();
      _but.clear();
      return ;
    }
  //std::cout << MTIME << " " <<  _id << " " << stm.str() << " D";
  while (read(_fd, &_event, sizeof(_event)) > 0)
    {
      if (_event.type == 129 && _but.size() <= _event.number)
	  _but.push_back(0);
      if (_event.type == 130 && _axe.size() <= _event.number)
	_axe.push_back(0);
    }
}

Key	Controler::getKey()
{
  Key	k;

  if (!isOk())
    return (k);
  if (_id == 0)
  {
  k.ptr(Key::HOR) = &_axe[3];
  k.ptr(Key::VERT) = &_axe[2];
  }
  else
  {
  k.ptr(Key::HOR) = &_axe[0];
  k.ptr(Key::VERT) = &_axe[1];
  }
  k.ptr(Key::A) = &_but[0];
  k.ptr(Key::B) = &_but[1];
  k.ptr(Key::X) = &_but[2];
  k.ptr(Key::Y) = &_but[3];
  k.ptr(Key::R) = &_but[4];
  k.ptr(Key::L) = &_but[5];
  return (k);
}

void	Controler::proc()
{
  if (_fd == -1)
    return ;
  while (read(_fd, &_event, sizeof(_event)) > 0)
    {
      if (_event.type == 1)
      {
	//std::cout << (int)_event.number << std::endl;
	_but[_event.number] = _event.value;
      }
      else if (_event.type == 2)
      {
	_axe[_event.number] = STICK_TO_SPEED(_event.value);
	//std::cout << (int)_event.number << " " << _axe[_event.number] << std::endl;
      }
    }
}
