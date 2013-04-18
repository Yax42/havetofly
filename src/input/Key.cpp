//
// Key.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:26:10 2013 Brunier Jean
// Last update Thu Apr 18 09:57:56 2013 Brunier Jean
//

#include "Key.hh"

Key::Key()
{
}

int	Key::operator[](int i) const
{
  return (_delta[i]);
}

int	Key::operator()(int i) const
{
  return (*_val[i]);
}


void	Key::update()
{
  for (int i = A; i < COUNT; i++)
    {
      _delta[i] = *_val[i] - _prevVal[i];
      _prevVal[i] = *_val[i];
    }
}

int	*&Key::ptr(int i)
{
  return (_val[i]);
}
