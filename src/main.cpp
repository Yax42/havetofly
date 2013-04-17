//
// main.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 09:30:33 2013 Brunier Jean
// Last update Wed Apr 17 20:50:07 2013 Brunier Jean
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

#define MAP_H	758
#define MAP_W	512

Mutex	mutex;

void	run()
{
  Input::create();
  GameLoader	gl(MAP_H, MAP_W);
  Display	dis(MAP_H, MAP_W);

  dis.loop();
  gl.loop();

  dis.join();
  Game::get()->quit();
  gl.join();
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
