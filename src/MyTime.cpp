/*
** Time.cpp for src in /home/brunie_j/local/nibbler/nibbler/src
**
** Made by Brunier Jean
** Login   <brunie_j@epitech.net>
**
** Started on  Tue Mar 05 15:30:16 2013 Brunier Jean
** Last update Wed Mar 20 10:51:34 2013 Brunier Jean
*/

#include "MyTime.hh"

int MyTime::_time = 0;

void	MyTime::reset()
{
  MyTime::_time = 0;
}

void	MyTime::run()
{
  MyTime::_time++;
}

int	MyTime::get()
{
  return (_time);
}
