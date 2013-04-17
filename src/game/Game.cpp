//
// Game.cpp for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 15:47:33 2013 Brunier Jean
// Last update Wed Apr 17 20:54:38 2013 Brunier Jean
//

#include "Game.hh"
#include "Input.hh"

Game	*Game::_inst = NULL;

/*************/
/* SINGLETON */
/*************/
Game	*Game::create(int h, int w)
{
  if (_inst == NULL)
    _inst = new Game(h, w);
  return (_inst);
}

Game	*Game::get()
{
  return (_inst);
}

void	Game::destroy()
{
  if (_inst != NULL)
    {
      delete _inst;
      _inst = NULL;
    }
}

void	Game::initLoop()
{
  _nbPlayers = _players.size();
}

/***************/
/* CONSTRUCTOR */
/***************/

Game::~Game()
{
  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    free (*i);
  _players.clear();
}

Game::Game(int h, int w) : ALoop(120)
{
  MyTime::reset();
  _height = h;
  _width = w;
}

bool		Game::manyTeams() const
{
  int		team = -1;

  for (Players::const_iterator i = _players.begin(); i != _players.end(); ++i)
    {
      if (team == -1 && (*i)->alive())
	team = (*i)->team();
      else if ((*i)->alive() && (*i)->team() != team)
	return (true);
    }
  return (false);
}

/********/
/* LOOP */
/********/
bool		Game::iterLoop()
{
  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    (*i)->init();
  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    (*i)->move();
  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    (*i)->process();
  MyTime::run();
  Input::get()->proc();
  return (true);
}

bool	Game::ifLoop()
{
  return (_nbPlayers == 1 || manyTeams());
}

/*********/
/* OTHER */
/*********/

void	Game::add(const Position &pos, int team, const Key &k)
{
  _players.push_back(new Player(pos, team, k));
}

/***********/
/* GETTERS */
/***********/

Players		&Game::players()
{
  return (_inst->_players);
}

int	Game::w()
{
  return (_inst->_width);
}

int	Game::h()
{
  return (_inst->_height);
}
