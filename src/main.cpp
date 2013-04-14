//
// main.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 09:30:33 2013 Brunier Jean
// Last update Sun Apr 14 11:45:53 2013 Brunier Jean
//

#include <pthread.h>

#include "Exception.hh"
#include "Graphics.hh"
#include "Input.hh"
#include "Player.hh"
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
    Game		game(768, 512);

    for (int i = 0; i < SDL_NumJoysticks(); i++)
      game.add(Position(40 + i * 5, i % 2 * 400 + 50), (i % 2) * 2, input->getCtrlKey(i));
    game.add(
	Position(40 + SDL_NumJoysticks() * 5, SDL_NumJoysticks() % 2 * 400 + 50),
	((SDL_NumJoysticks() % 2) * 2), input->getKBKey());
    ret = game.loop();
  } while (ret);
  input->quit();
  return (NULL);
}

void	*run_graphics(void *inputVoid)
{
  Input		*input = (Input *)inputVoid;
  Graphics	g(768, 1024);
  Wait		wait(60);

  while (!Input::isQuit())
    {
      if ((*input)[SDLK_p])
	g.switchFS();
      g.resetScreen(0xaaddaa);
      for (Players::iterator i = Game::players.begin(); i != Game::players.end(); ++i)
	if (i->alive())
	  i->bones().print(g);
      g.printScreen();
      wait.proc();
    }
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

int	main()
{
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
