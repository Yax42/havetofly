//
// Key.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:26:10 2013 Brunier Jean
// Last update Wed Apr 17 20:45:29 2013 Brunier Jean
//

#include "Key.hh"

Key::Key()
{
}

int	Key::operator[](int i)
{
  return (*_val[i]);
}

void	Key::resetActKey()
{
  *_val[A] = 0;
  *_val[B] = 0;
  *_val[X] = 0;
  *_val[Y] = 0;
}

int	*&Key::ptr(int i)
{
  return (_val[i]);
}
