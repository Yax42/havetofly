//
// main.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 09:30:33 2013 Brunier Jean
// Last update Wed Apr 24 10:24:21 2013 Brunier Jean
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
#include "RatioPosition.hh"
#include "Mutex.hh"

#define MAP_H	768
#define MAP_W	512

void	print_help()
{
  std::cout << "Debug flags:" << std::endl;
  std::cout << "      - No death\t1"<< std::endl;
  std::cout << "      - Slow down\t2"<< std::endl;
  std::cout << "      - Infinite jump\t4"<< std::endl;
  std::cout << "      - Print hitboxes\t8"<< std::endl;
  std::cout << "      - Print tech\t16"<< std::endl;
  std::cout << "      - Plane mode\t32"<< std::endl;
  std::cout << "      - Auto stun\t64"<< std::endl;
  std::cout << "      - Night mode\t128"<< std::endl;
  std::cout << "      - Player2 no move\t256"<< std::endl;
  exit(0);
}

int		g_debug = 0;
const int	&DEBUG = g_debug;

void	run()
{
  Input::create();
  GameLoader	gl(MAP_H, MAP_W);
  Display	dis(MAP_H, MAP_W);

  dis.loop();
  gl.loop();

  gl.join();
  dis.quit();
  dis.join();
  Input::destroy();
}

void	test()
{
  RatioPosition		pos = Position(100, 100);

  for (int i = 0; i < 100; i++)
  pos.y(pos.y() + 0.5);
  std::cout << pos << std::endl;

  exit(0);
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
