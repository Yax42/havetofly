//
// MovePlayer.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 19 22:29:54 2013 Brunier Jean
// Last update Sat Apr 20 10:29:19 2013 Brunier Jean
//

#include "Game.hh"
#include "MovePlayer.hh"
#include "const.hh"

const int	MovePlayer::nbIt = 10;

MovePlayer::MovePlayer(Position &speed, Position &pos,
    std::vector<bool>  &event, IAction *&doing) :
	_speed(speed), _pos(pos), _event(event), _doing(doing)
{
}

void	MovePlayer::init()
{
  _initPos = _pos;
  _finalPos = _pos + _speed;
  _count = 0;
  for (int i = 0; i < Event::COUNT; i++)
    _event[i] = false;

  if (_finalPos.x() <= BODY_SIZE)
    {
      _finalPos.x(BODY_SIZE);
      _event[Event::LEFT_WALL] = true;
      _event[Event::WALL] = true;
    }
  else if (_finalPos.x() >= Game::w() - BODY_SIZE)
    {
      _finalPos.x(Game::w() - BODY_SIZE);
      _event[Event::RIGHT_WALL] = true;
      _event[Event::WALL] = true;
    }
  if (_finalPos.y() <= BODY_SIZE)
    {
      _finalPos.y(BODY_SIZE);
      _event[Event::CEILING] = true;
    }
  else if (_finalPos.y() >= Game::h() + 40)
    {
      _finalPos.y(Game::h() + 40);
      _event[Event::FLOOR] = true;
    }
}


void	MovePlayer::proc()
{
  _count++;
  if (nbIt == _count)
    _pos = _finalPos;
  else
    _pos = _initPos + ((_speed * nbIt) / _count);

  if (_pos.x() <= BODY_SIZE)
    _pos.x(BODY_SIZE);
  else if (_pos.x() >= Game::w() - BODY_SIZE)
    _pos.x(Game::w() - BODY_SIZE);
  if (_pos.y() <= BODY_SIZE)
    _pos.y(BODY_SIZE);
  else if (_pos.y() >= Game::h() + 40)
    _finalPos.y(Game::h() + 40);

  for (Players::iterator i = Game::players().begin(); i != Game::players().end(); ++i)
    _doing->hit(**i);
}
