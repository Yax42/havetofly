//
// Tech.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 11 00:55:33 2013 Brunier Jean
// Last update Tue Apr 23 15:41:42 2013 Brunier Jean
//

#include "Tech.hh"
#include "Player.hh"

Tech::Tech(Player &player) : PassiveAction(player, IAction::TECH)
{
}

void		Tech::check()
{
  if (_open > 0)
    _open--;
  if (_count > 0)
    _count--;
  else if (_player.key[Key::L] == 1)
    _count = 80;
}

int		Tech::val()
{
  if (_count >= 40)
    _open = 10;
  return (_count >= 40);
}

void		Tech::print(Graphics &g) const
{
  if (_open)
    {
      for (int i = 0; i < 6; i++)
      {
        g.sponge(_bones[Bones::FOOT1], 10 + i * 4 - _open * 2, 10, 10, Angle(MTIME * 2, 0), 0xFFFFFF);
      }
    }
  if (_count == 0 || (DEBUG & 16) == 0)
    return ;
  if (_count > 40)
    for (int j = 0; j < Bones::COUNT; j++)
      for (int i = 0; i < 10; i++)
        g.circle(_bones[j] + Position(-5, 0), 5 + i, 0x0000FF);
  else
    for (int j = 0; j < Bones::COUNT; j++)
      for (int i = 0; i < 10; i++)
        g.circle(_bones[j] + Position(-5, 0), 5 + i, 0xFF0000);
}
