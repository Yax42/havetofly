//
// Player.hh for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 20:28:59 2013 Brunier Jean
// Last update Thu Apr 11 01:18:50 2013 Brunier Jean
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include "IState.hh"
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

class Player
{
public:
  enum Event
    {
      CEILING,
      LEFT_WALL,
      RIGHT_WALL,
      HIT,
      COUNT
    };
private:
  Position	_pos;
  Bones		_bones;
  Position	_speed;
  IState	*_state;
  IAction	*_action;
  int		_stun;

public:

  Player(const Position &pos);
  ~Player();

  /* SETTERS */
  void			operator++();
  void			operator=(Position const &speed);
  void			x(const Distance &s);
  void			y(const Distance &s);
  bool			operator[](int k);
  bool			operator()(int e);
  void			touch() const;
  void			stop();
  void			stun(int v);

  /* GETTERS */
  bool			stun() const;
  Position const	&pos() const;
  Position const	&speed() const;
  Distance		x() const;
  Distance		y() const;
  Bones			&bones();
  Action		&action(int a);
};


#endif /* !PLAYER_HH_ */
