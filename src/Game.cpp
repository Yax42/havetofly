//
// Game.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 15:47:33 2013 Brunier Jean
// Last update Sat Apr 13 16:20:43 2013 Brunier Jean
//

#include "Game.hh"

Game::Game(int h, int w) : _height(h), _width(w)
{
}

void		Game::wait()
{
  int		time;

  ftime(&_t2);
  time = ((_t2.time - _t1.time) * 1000 + (_t2.millitm - _t1.millitm));
  time = 16 - time;
  if (time > 0)
    usleep(time * 1000);
  ftime(&_t1);
}

void		Game::loop()
{
  ftime(&_t1);
  while (1)
    {
      for(Players::iterator i = _players.begin(); i < _players.end(); ++i)
  	i->init();
      for(Players::iterator i = _players.begin(); i < _players.end(); ++i)
  	i->move();
      for(Players::iterator i = _players.begin(); i < _players.end(); ++i)
  	i->process();
      MyTime::run();
      wait();
    }
}
