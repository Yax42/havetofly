//
// MovePlayer.hh for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 19 22:29:58 2013 Brunier Jean
// Last update Tue Apr 23 01:05:59 2013 Brunier Jean
//

#ifndef MOVEPLAYER_HH_
# define MOVEPLAYER_HH_

# include <vector>

# include "Position.hh"
# include "RatioPosition.hh"
# include "Event.hh"
# include "IAction.hh"

class MovePlayer
{
public:
  static const int	nbIt;

private:
  RatioPosition		&_speed;
  Position		&_pos;
  std::vector<bool>	&_event;
  IAction		*&_doing;
  Player		*_player;
  Position		_initPos;
  int			_count;


public:
  ~MovePlayer(){}
  MovePlayer(RatioPosition &speed, Position &pos,
      std::vector<bool> &event, IAction *&doing, Player *player);
  void	init();
  void	proc();
};

#endif /* !MOVEPLAYER_HH_ */
