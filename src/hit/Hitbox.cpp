//
// Hitbox.cpp for hit in /home/brunie_j/local/my/havetofly/src/hit
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 15:41:09 2013 Brunier Jean
// Last update Thu Apr 18 10:52:43 2013 Brunier Jean
//

#include "Hitbox.hh"
#include "Graphics.hh"

Hitbox::Hitbox(const Distance &ray, const Position &center,
    const Position &playerPos, const int &orient) :
	_ray(ray), _center(center), _playerPos(playerPos), _orient(orient)
{
}

bool		Hitbox::touch(const Hitbox &other) const
{
  Position	pos1 = _center.switchX(_orient == -1) + _playerPos;
  Position	pos2 = other._center.switchX(other._orient == -1) + other._playerPos;
  //std::cout <<(pos1 - pos2).distance().abs() << " " << _ray + other._ray<< std::endl;
  return ((pos1 - pos2).distance().abs() < _ray + other._ray);
}

void	Hitbox::print(Graphics &g, int color) const
{
  Position	pos = _center.switchX(_orient == -1) + _playerPos;
  g.circle(pos, _ray, color);
  g.circle(pos, _ray - 1, 0xffffff - color);
  g.circle(pos, _ray - 2, color);
}
