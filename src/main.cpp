//
// main.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 09:30:33 2013 Brunier Jean
// Last update Sat Apr 20 16:22:24 2013 Brunier Jean
//

#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <string>

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

void	print_help()
{
  std::cout << "Debug flags:" << std::endl;
  std::cout << "      - No death\t1"<< std::endl;
  std::cout << "      - Slow down\t2"<< std::endl;
  std::cout << "      - Infinite jump\t4"<< std::endl;
  std::cout << "      - Print hitboxes\t8"<< std::endl;
  std::cout << "      - Print tech\t16"<< std::endl;
  exit(0);
}

int		g_debug = 0;
const int	&DEBUG = g_debug;

void	run()
{
  Mutex	mutex;

  Input::create();
  GameLoader	gl(MAP_H, MAP_W, mutex);
  Display	dis(MAP_H, MAP_W, mutex);

  dis.loop();
  gl.loop();

  gl.join();
  dis.quit();
  mutex.unlock();
  dis.join();
  Input::destroy();
}

int	main(int ac, char **av)
{
  srand(time(NULL));
  Math::init();
  if (ac > 1 && std::string(av[1]) == "-h")
    print_help();
  if (ac > 1)
    g_debug = atoi(av[1]);

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
