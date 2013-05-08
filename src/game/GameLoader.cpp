//
// GameLoader.cpp for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 12:14:35 2013 Brunier Jean
// Last update Tue May 07 23:37:19 2013 Brunier Jean
//

#include "GameLoader.hh"
#include "Input.hh"
#include "Game.hh"
#include "Input.hh"
#include "const.hh"
#include "Mutex.hh"

int	GameLoader::_score[20];

GameLoader::GameLoader(int h, int w) : ALoop(2), _h(h), _w(w), _ret(true)
{
  for (int i = 0; i < 20; i++)
    _score[i] = 0;
  (void) _ret;
}

bool	GameLoader::iterLoop()
{
  static const int color[] =
    {
      0xFF0000,
      0x0000FF,
      0x005500,
      0x880088,
      0xFF00FF,
      0xFF8800
    };
  bool		ret;
  Game		*game = Game::create(_h, _w);

  Input_.update();
  if (DEBUG & 256)
    game->add(Position(400, 256), 100, Input_.getKBKey(),  color[5]);
  for (int i = 1; i <= Input_.nbCtrl(); i++)
    game->add(Position(400, 50 + i * 200), i, Input_.getCtrlKey(i - 1),  color[i]);
  if (DEBUG || Input_.nbCtrl() == 0)
    game->add(Position(400, 50), 0, Input_.getKBKey(), color[0]);
  ret = game->loop();
  scoring();
  Game::destroy();
  return (ret);
}

void	GameLoader::scoring()
{
  int	winTeam = -1;
  for(Players::iterator i = Game::players().begin(); i != Game::players().end(); ++i)
  {
    if ((*i)->alive())
      {
	if (winTeam == -1)
	  winTeam = (*i)->team();
	else if (winTeam != (*i)->team())
	  return ;
      }
  }
  if (winTeam != -1)
    _score[winTeam]++;
}

int	GameLoader::getScore(int id)
{
  return (_score[id]);
}
