//
// Player.hh for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 20:28:59 2013 Brunier Jean
// Last update Sat Apr 13 15:12:32 2013 Brunier Jean
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <vector>
# include <list>

# include "IAction.hh"
# include "Bones.hh"
# include "Position.hh"

enum Keys
{
  K_LEFT,
  K_RIGHT,
  K_UP,
  K_DOWN,
  K_A,
  K_B,
  K_R,
  K_L,
  K_COUNT
};

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
  static std::list<Player&>	_player;
  Position			_pos;
  int				_team;
  std::vector<bool>		_event;
  std::vector<IAction*>		_action;
  Bones				_bones;
  Position			_speed;
  IAction			*_doing;
  const Hit			*_hit;

public:

  Player(const Position &pos, int team);
  ~Player();

  /* PROCESS */
  void			init();
  void			move();
  void			process();
  void			hit();

  /* SETTERS */
  void			operator++();
  void			operator=(Position const &speed);
  IAction		*operator[](int action);
  int			operator()(int event);
  int			key(int k);

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
  Action		&action(int a);
};


#endif /* !PLAYER_HH_ */
