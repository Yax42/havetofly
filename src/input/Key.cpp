//
// Key.cpp for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:26:10 2013 Brunier Jean
// Last update Sun Apr 21 23:50:10 2013 Brunier Jean
//

#include "Math.hh"
#include "Key.hh"

Key::Key()
{
}

int	Key::operator[](int i) const
{
  if (i > VERT)
    return (_delta[i]);
  if (MPOS(*_val[i]) < 250)
    return (0);
  if ((MPOS(*_val[VERT]) + 200 > MPOS(*_val[HOR])) ==
      (i == VERT))
    return (MSIGN(*_val[i]));
  return (0);
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
