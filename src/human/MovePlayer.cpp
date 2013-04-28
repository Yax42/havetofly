//
// MovePlayer.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 19 22:29:54 2013 Brunier Jean
// Last update Thu Apr 25 23:28:50 2013 Brunier Jean
//

#include "Game.hh"
#include "MovePlayer.hh"
#include "const.hh"

const int	MovePlayer::nbIt = 10;

MovePlayer::MovePlayer(RatioPosition &speed, Position &pos,
    std::vector<bool>  &event, IAction *&doing, Player *player) :
	_speed(speed), _pos(pos), _event(event), _doing(doing), _player(player)
{
}

void	MovePlayer::init()
{
  _initPos = _pos;
  _count = 0;
  for (int i = 0; i < Event::COUNT; i++)
    _event[i] = false;
}

void	MovePlayer::proc()
{
  _count++;
  _pos = _initPos + ((_speed * _count) / nbIt);
  if (_pos.x() <= BODY_SIZE)
    {
      _event[Event::LEFT_WALL] = true;
      _event[Event::WALL] = true;
      _pos.x(BODY_SIZE);
    }
  else if (_pos.x() >= Game::w() - BODY_SIZE)
    {
      _pos.x(Game::w() - BODY_SIZE);
      _event[Event::RIGHT_WALL] = true;
      _event[Event::WALL] = true;
    }
  if (_pos.y() <= BODY_SIZE)
    {
      _event[Event::CEILING] = true;
      _pos.y(BODY_SIZE);
    }
  else if (_pos.y() >= Game::h() + Game::deep)
    {
      _pos.y(Game::h() + Game::deep);
      _event[Event::FLOOR] = true;
    }
  for (Players::iterator i = Game::players().begin(); i != Game::players().end(); ++i)
    if (*i != _player)
      if (_doing->hit(**i))
        {
	  _event[Event::DID_HIT] = true;
  	  (*_player)[IAction::HIT_LAGG]->init(_doing->hitLagg());
	}
}
