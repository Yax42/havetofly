//
// Game.cpp for game in /home/brunie_j/local/my/havetofly/src/game
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Apr 13 15:47:33 2013 Brunier Jean
// Last update Sun May 12 15:35:58 2013 Brunier Jean
//

#include "Game.hh"
#include "GameLoader.hh"
#include "Input.hh"
#include "const.hh"
#include "MovePlayer.hh"
#include "Event.hh"

Game		*Game::_inst = NULL;
const int	Game::deep = 120;

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
  _alone = _players.size() == 1;
  _time = 0;
}

/***************/
/* CONSTRUCTOR */
/***************/
Game::~Game()
{
  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    delete (*i);
}

Game::Game(int h, int w) : APrintable((DEBUG & 2 ) ? 30 : (DEBUG & 512) ? 1 : 120), _height(h), _width(w)
{
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
  int		cpt;

  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    (*i)->init();

  for (int j = 0; j < MovePlayer::nbIt; j++)
  {
    cpt = 0;
    for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
      if ((DEBUG & 256) == 0 || cpt++ != 0)
	(*i)->move();
  }

  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    (*i)->procHit();

  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    if ((**i)[IAction::HIT_LAGG]->val() == 0)
      (*i)->process();

  for(Players::iterator i = _players.begin(); i != _players.end(); ++i)
    (*i)->upKeys();
  if (Input_(SDLK_LALT) && Input_(SDLK_k))
    {
      switchPrint(_setKeys);
      killAll();
    }
  _time++;
  return (true);
}

bool	Game::ifLoop()
{
  return ((_alone && (*_players.begin())->alive()) || manyTeams());
}

/*********/
/* OTHER */
/*********/
void	Game::add(const Position &pos, int team, const Key &k, int color)
{
  _players.push_back(new Player(pos, team, k, color));
}

void	Game::killAll()
{
  if (players().size() == 0)
    return ;
  for(Players::iterator i = players().begin(); i != players().end(); ++i)
    (*i)->kill();
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

int	Game::time()
{
  return (_inst->_time);
}

/*************/
/* PRINTABLE */
/*************/
#define scorePos(y, x)		(Position(y * 52 + 40, x * 40 + 140))

void	Game::print(Graphics &g)
{
  int	cpt;
  g.setCap(0,256);
  g.resetScreen(0);
  for (int i = 0; i < (int) _players.size(); i++)
    {
      cpt = 0;
      for (Players::iterator j = _players.begin(); j != _players.end(); ++j)
        {
	  if ((*j)->team() != i)
	    continue ;
	  g.rectangle(Position(i * 52 + 30, cpt * 30 + 10),
			Position(i * 52 + 50, cpt * 30 + 30),
			(*j)->color());
	  if (cpt++ == 0)
	    g.line (Position(i * 52 + 65, 0), Position(i * 52 + 60, 256), Color::WHITE);
	}
      for (int j = 0; j < GameLoader::getScore(i) % 4; j++)
        g.circle(scorePos(i, j), 5, Color::RED);
      for (int j = 0; j < (GameLoader::getScore(i) / 4) % 4; j++)
        g.circle(scorePos(i, j), 9, Color::BLUE);
      for (int j = 0; j < (GameLoader::getScore(i) / 16) % 4; j++)
        g.circle(scorePos(i, j), 13, Color::YELLOW);
      for (int j = 0; j < (GameLoader::getScore(i) / 64); j++)
        g.circle(scorePos(i, j), 19, Color::GREEN);
    }

  g.setCap(256, 512 + 256);
  if ((DEBUG & 128) == 0)
    g.resetScreen(0xaaee00 | MGRAD_CAP(MTIME / 10, 0, 255));
  for (Players::iterator i = _players.begin(); i != _players.end(); ++i)
    {
      if ((*i)->alive())
	(*i)->print(g);
    }
  g.setCap(512 + 256, g.w());
  g.resetScreen(0);
  g.setCap();
}
