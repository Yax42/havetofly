//
// Hit.hh for hit in /home/brunie_j/local/my/havetofly/src/hit
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 22:46:44 2013 Brunier Jean
// Last update Mon Apr 22 01:45:02 2013 Brunier Jean
//

#ifndef HIT_HH_
# define HIT_HH_

# include <list>
# include "Hitbox.hh"

class Player;

class Hit
{
public:
  enum
    {
      ORIENT,
      NONE,
      WALL
    };
private:
  int				_stun;
  Position			_speed;
  const int			&_orient;
  int				_type;
  std::list<Hitbox>		_hb;
  std::list<Player const*>	_players;

public:
  Hit(int stun, const Position &speed, const int &orient, int type = ORIENT);
  ~Hit() {}
  int	go(Player &ennemy) const;
  bool	focus(Player &ennemy);
  void	reset();
  void	add(const Distance &ray, const Position &center, const Position &playerPos);
  void	print(Graphics &g) const;
};

#endif /* !HIT_HH_ */
