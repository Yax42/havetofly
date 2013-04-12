//
// Hit.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 22:46:44 2013 Brunier Jean
// Last update Thu Apr 11 00:27:31 2013 Brunier Jean
//

#ifndef HIT_HH_
# define HIT_HH_

# include <list>

# include "Hitbox.hh"

class Player;

class Hit
{
private:
  Hitbox		_hb;
  int			_stun;
  Distance		_speed;
  const Player		&_player;
  std::list<Player *>	_players;

public:
  Hit(const Position &topL,
      const Position &botR,
      const Position &center,
      int stun, Distance speed, const Player &player);
  ~Hit();
  void	focus(Player &ennemy);
  void	reset();
};

#endif /* !HIT_HH_ */
