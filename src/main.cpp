//
// main.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 09:30:33 2013 Brunier Jean
// Last update Fri Apr 19 10:06:00 2013 Brunier Jean
//

#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

#include "Math.hh"
#include "Exception.hh"
#include "Display.hh"
#include "Input.hh"
#include "Player.hh"
#include "MyTime.hh"
#include "GameLoader.hh"
#include "Game.hh"
#include "Mutex.hh"

#define MAP_H	920
#define MAP_W	512

/* FLAGS :
 *	NORMAL_DEBUG	1
 * 	SLOW_DOWN	2
 * 	INFINIT_JUMP	4
 * 	PRINT_HITBOX	8
*/

int		g_debug = 1;
const int	&DEBUG = g_debug;

void	run()
{
  Mutex	mutex;

  Input::create();
  GameLoader	gl(MAP_H, MAP_W, mutex);
  Display	dis(MAP_H, MAP_W, mutex);

  mutex.lock();
  dis.loop();
  gl.loop();

  gl.join();
  dis.quit();
  mutex.unlock();
  dis.join();
  Input::destroy();
}

void	test()
{
  for (int i = -100; i < 100; i += 1)
    {
      Position	pos(Angle(i, 0), 100);

      //std::cout << i << "\t"  << Angle(i, 0).deg() << std::endl;
      //_toDeg[i] = double(i) * 180 / M_PI / MRATIO_UNIT;
      //std::cout << i << "\t"  << pos.angle().deg() << "\t" <<pos.distance() << "\t" << pos << std::endl;
      //std::cout << "[" << i << "\t"  << pos.angle().deg() << "\t" << pos << std::endl;
      //std::cout << Math::acos(i / 100.0) << std::endl;
      //std::cout << i << " " << Math::sqrt(i).intVal() << " " <<Math::sqrt(i).longVal() << std::endl;
      //Math::sqrt(i);
    }
  exit(0);
}

int	main()
{
  srand(time(NULL));
  Math::init();
  //test();

  try
    {
      run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
