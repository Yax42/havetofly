//
// Player.hh for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 20:28:59 2013 Brunier Jean
// Last update Sun Apr 14 11:13:16 2013 Brunier Jean
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <vector>
# include <list>

# include "IAction.hh"
# include "Bones.hh"
# include "Position.hh"
# include "Key.hh"

# include "Hit.hh"

namespace Event
{
  enum
    {
      FLOOR,
      CEILING,
      LEFT_WALL,
      RIGHT_WALL,
      WALL,
      HIT,
      COUNT
    };
}

class Player
{
private:
  Position			_pos;
  bool				_alive;
  int				_team;
  Key				_keys;
  Bones				_bones;
  std::vector<bool>		_event;
  std::vector<IAction*>		_action;
  Position			_speed;
  IAction			*_doing;
  Hit const			*_hit;

public:

  Player(const Position &pos, int team, const Key &k);
  ~Player();

  /* PROCESS */
  void			init();
  void			move();
  void			process();
  void			hit(const Hit *hit);

  /* SETTERS */
  void			operator++();
  void			operator=(Position const &speed);
  IAction		*operator[](int action);
  int			operator()(int event);
  int			&key(int k);

  /* SPEED */
  const Distance	&sx() const;
  const Distance	&sy() const;
  void			sx(const Distance &s);
  void			sy(const Distance &s);
  Position const	&speed() const;

  /* POSITION */
  Position const	&pos() const;
  int			x() const;
  int			y() const;

  /* GETTERS */
  Bones			&bones();
  void			kill();
  bool			alive() const;
  int			team() const;
  operator const Hitbox() const;
};

#endif /* !PLAYER_HH_ */
