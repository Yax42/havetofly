//
// AThrowable.cpp for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 22 01:23:23 2013 Brunier Jean
// Last update Tue Apr 23 23:09:34 2013 Brunier Jean
//

#include "Math.hh"
#include "AThrowable.hh"
#include "MovePlayer.hh"
#include "Game.hh"
#include "const.hh"

const int	AThrowable::SIZE = 64;
AThrowable::AThrowable(const Position &pos, const RatioPosition &speed,
  int stun, const Position &hitSpeed, const Player &player, int type) :
	_pos(pos), _speed(speed), _alive(true), _orient(MSIGN(speed.x())),
  _hit(stun, hitSpeed, _orient, 10, true, type), _player(player)
{

}

bool		AThrowable::isAlive() const
{
  return (_alive);
}

void	AThrowable::init()
{
  _initPos = _pos;
  _count = 0;
  _orient = MSIGN(_speed.x());
}

void	AThrowable::proc()
{
  _count++;
  _pos = _initPos + ((_speed * _count) / MovePlayer::nbIt);
  if (_pos.x() <= -SIZE ||
      _pos.x() >= Game::w() + BODY_SIZE ||
      _pos.y() <= -SIZE  ||
      _pos.y() >= Game::h() + Game::deep + SIZE)
    _alive = false;

  for (Players::iterator i = Game::players().begin(); i != Game::players().end(); ++i)
    if (*i != &_player)
      if (_hit.focus(**i))
        {
	  if (!(**i)[IAction::TECH]->val())
            (*i)->hit(&_hit);
	  effect(**i);
	  _alive = false;
	}
}

void		AThrowable::move()
{
}

void		AThrowable::effect(Player &)
{
}

void		AThrowable::printHB(Graphics &g) const
{
  _hit.print(g);
}
