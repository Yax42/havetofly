//
// Death.cpp for passive in /home/brunie_j/local/my/havetofly/src/action/passive
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 19 23:17:27 2013 Brunier Jean
// Last update Fri Apr 19 23:22:33 2013 Brunier Jean
//

#include "Death.hh"

Death::Death(Player &player) : PassiveAction(player, DEATH)
{
}

void		Death::check()
{
  if (_player(Event::FLOOR) && !DEBUG)
    _player.kill();
}
