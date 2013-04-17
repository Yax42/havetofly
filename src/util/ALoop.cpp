//
// ALoop.cpp for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 11:44:03 2013 Brunier Jean
// Last update Wed Apr 17 17:50:37 2013 Brunier Jean
//

#include "ALoop.hh"

ALoop::ALoop(int fps) : _quit(false), _wait(fps)
{
}

void	ALoop::loop()
{
  pthread_create(&_thread, 0, startThreadWrapper, this);
}

void		*ALoop::startThreadWrapper(void *obj)
{
  return ((void *) (((ALoop *) obj)->actualLoop()));
}

bool		ALoop::actualLoop()
{
  initLoop();
  while (ifLoop())
    {
      if (!iterLoop() || _quit)
	return (false);
      _wait.proc();
    }
  return (true);
}

bool		ALoop::join()
{
  void		*ret;

  pthread_join(_thread, &ret);
  return ((bool) ret);
}

void		ALoop::endLoop()
{
}

void		ALoop::initLoop()
{
}

bool		ALoop::ifLoop()
{
  return (true);
}

void		ALoop::quit()
{
  _quit = true;
}
