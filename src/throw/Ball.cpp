//
// Ball.cpp for throw in /home/brunie_j/local/my/havetofly/src/throw
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 23 02:41:46 2013 Brunier Jean
// Last update Tue Apr 23 16:17:10 2013 Brunier Jean
//

#include "Ball.hh"

Ball::Ball(const Player &player, const Angle &a) :
	AThrowable(player.pos(), RatioPosition(a, 6), 30, Position(1, 1), player)
{
  _hit.add(20, Position(), _pos);
  _val1 = 20;
}

void		Ball::move()
{
  //std::cout << _val1 << _alive <<std::endl;
  if (_val1 == 0)
    _alive = false;
  _speed.y(_speed.yRatio() + 0.1);
}

void		Ball::print(Graphics &g) const
{
  g.circleFull(_pos, 13, 0xFFFF00);
}
