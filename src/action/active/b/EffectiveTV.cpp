//
// EffectiveTV.cpp for b in /home/brunie_j/local/my/havetofly/src/action/active/b
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun May 05 20:57:29 2013 Brunier Jean
// Last update Tue May 07 11:09:04 2013 Brunier Jean
//

#include "EffectiveTV.hh"
#include "Television.hh"

EffectiveTV::EffectiveTV(Player &player) : AAction(player, EFFECTIVE_TV, NULL)
{
}

void	EffectiveTV::init(int v)
{
  if (v == 0)
    _patern = *_paternPtr;
  _open = v + 1;
  _count = 90;
  _ok = true;
  _speed = _player.speed();
  _player = Position();
}

bool	EffectiveTV::allow(int)
{
  return (false);
}

IAction		*EffectiveTV::step()
{
  if(_open)
    {
      _open--;
      if (_open == 0)
	  _patern = *_paternPtr;
      else
	return (this);
    }
  if (_ok && _player.key.cur() && _patern.size() > 0)
    {
      if (_player.key.cur() == _patern.front())
	_patern.pop_front();
      else
	_ok = false;
    }
  if (_patern.size() == 0)
    {
      _player[STUN]->set(-1);
      return (_player[INERTIE]);
    }
  if (_count)
    return (this);
  _player[STUN]->set(100);
  _player = _speed;
  return (_player[STUN]);
}

bool		EffectiveTV::request()
{
  return (false);
}


void		EffectiveTV::check()
{
  if (_open == 0 && _count != 0)
    _count--;

}

void		EffectiveTV::set(int)
{
}

void		EffectiveTV::setPatern(const std::list<char> &patern)
{
  _paternPtr = &patern;
}

int		EffectiveTV::val()
{
  return (_count);
}

/************/
/* GRAPHICS */
/************/
void		EffectiveTV::upBones()
{
}

void		EffectiveTV::print(Graphics &g) const
{
  if (isActive() && !_open)
    {
      /*
      Position		pos1 =
	_pos + Position(-30, (_orient == -1 ? -30 - Television::size : 30));
      Position		pos2 = pos1 + Position(Television::size, Television::size);
      Position		center = (pos1 + pos2) / 2;
      */

      g.circleLaid(_player.pos(), _count - 10, Color::BLACK, Color::WHITE);
      g.circleLaid(_player.pos(), _count - 20, Color::BLACK, Color::WHITE);
      g.circleLaid(_player.pos(), _count, Color::BLACK, Color::WHITE);
      /*
      g.rectangle(pos1, pos2, 0x009900);
      g.rectangle(pos1 - Position(2, 2), pos2 + Position(2, 2), 0x009900);
      for (int i = 0; i < 10; i++)
	g.line(pos1 + Position(_count + rand() % 10, rand() % 100),
	       pos1 + Position(_count + rand() % 10, rand() % 100),
	       0x009900);
	       */
    }
}
