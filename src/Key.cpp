//
// Key.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:26:10 2013 Brunier Jean
// Last update Sun Apr 14 01:57:26 2013 Brunier Jean
//

#include "Key.hh"

Key::Key()
{
  _val.resize(Key::COUNT);
}

int	&Key::operator[](int i)
{
  return (*_val[i]);
}
