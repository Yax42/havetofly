//
// Key.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:26:10 2013 Brunier Jean
// Last update Sun Apr 14 18:39:51 2013 Brunier Jean
//

#include "Key.hh"

Key::Key()
{
}

int	*Key::operator[](int i)
{
  return (_val[i]);
}

int	*&Key::ptr(int i)
{
  return (_val[i]);
}
