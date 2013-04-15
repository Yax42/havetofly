//
// main.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 09:30:33 2013 Brunier Jean
// Last update Tue Apr 16 00:00:42 2013 Brunier Jean
//

#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

#include "Math.hh"
#include "Exception.hh"
#include "Graphics.hh"
#include "Input.hh"
#include "Player.hh"
#include "MyTime.hh"
#include "Game.hh"

void	*run_input(void *input)
{
  ((Input *)input)->loop();
  return (NULL);
}

void	*run_game(void *inputVoid)
{
  Input		*input = (Input *)inputVoid;
  bool		ret;
  do
  {
    MyTime::reset();
    Game		game(768, 512);

    for (int i = 0; i < SDL_NumJoysticks(); i++)
      game.add(Position(40 + i * 5, i % 2 * 400 + 50), (i % 2) * 2, input->getCtrlKey(i));
    game.add(
	//Position(40 + SDL_NumJoysticks() * 5, SDL_NumJoysticks() % 2 * 400 + 50),
	Position(300, 300),
	((SDL_NumJoysticks() % 2) * 2), input->getKBKey());
    ret = game.loop();
  } while (ret);
  input->quit();
  return (NULL);
}

void	*run_graphics(void *inputVoid)
{
  Input		*input = (Input *)inputVoid;
  Graphics	g(768, 512);
  Wait		wait(60);
  input->update();
  while (!Input::isQuit() && !(*input)[SDLK_ESCAPE])
    {
      if ((*input)[SDLK_p])
	g.switchFS();
      g.resetScreen(0xaaff77);
      for (Players::iterator i = Game::players.begin(); i != Game::players.end(); ++i)
	if ((*i)->alive())
	  (*i)->bones().print(g);

      g.printScreen();
      wait.proc();
    }
  Game::quit = true;
  return (NULL);
}

void	run()
{
  pthread_t	thread_input;
  pthread_t	thread_game;
  pthread_t	thread_graphics;
  Input		input;

  pthread_create(&thread_input, NULL, &run_input, &input);
  pthread_create(&thread_graphics, NULL, &run_graphics, &input);
  pthread_create(&thread_game, NULL, &run_game, &input);

  pthread_join(thread_input, NULL);
  pthread_join(thread_graphics, NULL);
  pthread_join(thread_game, NULL);
}

void	test()
{
  for (int i = -100; i < 100; i += 1)
    {
      Position	pos(Angle(i, 0), 100);

      //std::cout << i << "\t"  << Angle(i, 0).deg() << std::endl;
      //_toDeg[i] = double(i) * 180 / M_PI / MRATIO_UNIT;
      //std::cout << i << "\t"  << pos.angle().deg() << "\t" <<pos.distance() << "\t" << pos << std::endl;
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
  test();

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
