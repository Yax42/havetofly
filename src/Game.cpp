//
// Game.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 15:47:33 2013 Brunier Jean
// Last update Sun Apr 14 11:03:46 2013 Brunier Jean
//

#include "Game.hh"
#include "Input.hh"

int	Game::_width;
int	Game::_height;
Players	Game::players;

Game::~Game()
{
  players.clear();
}

Game::Game(int h, int w) : _wait(60)
{
  _height = h;
  _width = w;
}

bool		Game::manyTeams() const
{
  int		team = -1;

  for (Players::iterator i = Game::players.begin(); i != Game::players.end(); ++i)
    {
      if (team == -1 && i->alive())
	team = i->team();
      else if (i->alive() && i->team() != team)
	return (true);
    }
  return (false);
}

bool		Game::loop()
{
  int		_nbPlayers = players.size();

  while (_nbPlayers == 1 || manyTeams())
    {
      for(Players::iterator i = players.begin(); i != players.end(); ++i)
  	i->init();
      for(Players::iterator i = players.begin(); i != players.end(); ++i)
  	i->move();
      for(Players::iterator i = players.begin(); i != players.end(); ++i)
  	i->process();
      MyTime::run();
      _wait.proc();
      if (Input::isQuit())
	return (false);
    }
  return (true);
}

void	Game::add(const Position &pos, int team, const Key &k)
{
  players.push_back(Player(pos, team, k));
}

int	Game::w()
{
  return (_width);
}

int	Game::h()
{
  return (_height);
}
