//
// ThrowShuriken.cpp for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue Apr 23 11:58:18 2013 Brunier Jean
// Last update Sun May 05 22:09:24 2013 Brunier Jean
//

#include "ThrowShuriken.hh"
#include "Shuriken.hh"

const int	ThrowShuriken::_time = 780;
const int	ThrowShuriken::_timeMax = 800;

ThrowShuriken::ThrowShuriken(Player &player) : AAction(player, THROW_SHURIKEN, NULL)
{
}

void	ThrowShuriken::init(int)
{
  if (_open == 0)
    _open = _timeMax;
  else
    _count = _timeMax;
  _player.sy(MCAP(_player.sy(), -5, 0));
}

bool	ThrowShuriken::allow(int)
{
  return (false);
}

IAction		*ThrowShuriken::step()
{
  return (_player[INERTIE]);
}

bool		ThrowShuriken::request()
{
  return ((!_open || !_count) && _player.key[Key::X] == 1 && !_player.key[Key::HOR] && !_player.key[Key::VERT]);
}

void		ThrowShuriken::check()
{
  if (_count == _timeMax - 10)
    _player.doThrow(new Shuriken(_player));
  if (_open == _timeMax - 10)
    _player.doThrow(new Shuriken(_player));
  if (_count)
    _count--;
  if (_open)
    _open--;
}

void		ThrowShuriken::set(int)
{
}

int		ThrowShuriken::val()
{
  return (_open <= _time && _count <= _time);
}

/************/
/* GRAPHICS */
/************/
void		ThrowShuriken::upBones()
{
}

void		ThrowShuriken::print(Graphics &g) const
{
  if (!_count && !_open)
    {
      for (int i = 0; i < 4; i++)
        g.sponge(_bones[Bones::HAND2], (MTIME / 5 + i) % 6 + 1, 6, 3, Angle(MTIME * 3, 0), 0);
    }
  else if (!_count || !_open)
    {
      for (int i = 0; i < 4; i++)
	g.circle(_bones[Bones::HAND2], (MTIME / 5 + i) % 5 + 1, 0);
    }
  if (_open > _time || _count > _time)
    {
      int	val = MMAX(_open, _count) - _time;

      _bones.angle[Bones::HAND2] = Angle(0, 0);
      _bones.angle[Bones::ELBOW2] = Angle(val * (-10) + 150, 0);
    }
}
