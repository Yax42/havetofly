//
// MovePlayer.hh for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 19 22:29:58 2013 Brunier Jean
// Last update Mon Apr 22 01:51:16 2013 Brunier Jean
//

#ifndef MOVEPLAYER_HH_
# define MOVEPLAYER_HH_

# include <vector>

# include "Position.hh"
# include "Event.hh"
# include "IAction.hh"

class MovePlayer
{
public:
  static const int	nbIt;

private:
  Position		&_speed;
  Position		&_pos;
  std::vector<bool>	&_event;
  IAction		*&_doing;
  const Player		*_player;
  Position		_finalPos;
  Position		_initPos;
  int			_count;


public:
  ~MovePlayer(){}
  MovePlayer(Position &speed, Position &pos,
      std::vector<bool> &event, IAction *&doing, const Player *player);
  void	init();
  void	proc();
};

#endif /* !MOVEPLAYER_HH_ */
