//
// Player.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 22:50:06 2013 Brunier Jean
// Last update Sat Apr 13 15:33:21 2013 Brunier Jean
//

#include "ActionFactory.hh"
#include "Player.hh"


/****************/
/* CONSTRUCTORS */
/****************/

Player::~Player(){}

Player::Player(const Position &pos, int team) : _pos(pos), _team(team)
{
  for (int i = 0; i < IAction::COUNT; i++)
    _action[i] = ActionFactory.get(i);
  _doing = _action[IAction::INERTIE];
  _player.push_back(*this);
}

void	Player::operator++()
{
  if (_speed.yDist() > -10)
    _speed.yDist() -= 0.1;
}

void	Player::operator=(Position const &speed)
{
  _speed = speed;
}

int		Player::operator[](int a)
{
  return (action[a].val());
}

int		Player::operator()(int event)
{
  return (_event[event]);
}

/************/
/*  PROCESS */
/************/

void		Player::init()
{
  for (int i = 0; i < Event::COUNT; i++)
    _event[i] = false;
  _hit = NULL;
}

void		Player::move()
{
  _pos += _speed;
  if (pos.x() <= BODY)
    {
      pos.x(BODY);
      _event[Event::LEFT_WALL] = true;
      _event[WALL] = true;
    }
  else if (pos.x() >= MAP_W - BODY)
    {
      pos.x(MAP_W - BODY);
      _event[Event::RIGHT_WALL] = true;
      _event[WALL] = true;
    }
  if (pos.y() <= BODY)
    {
      pos.y(BODY);
      _event[Event::CEILING] = true;
    }
  else if (pos.y() >= MAP_H - BODY)
    {
      pos.y(MAP_H - BODY);
      _event[Event::FLOOR] = true;
    }
  std::for_each(_player.begin(), _player.end(), _doing->hit);
}

void		Player::process()
{
  int		tmp;
  if (_hit != NULL)
    {
      tmp = _hit->go();
      if (tmp > 0)
        {
	  _doing = _action[STUN];
	  _doing->init(tmp);
	}
      else
        _doing = _action[INERTIE];
    }
  for (int i = 0; i < Action::COUNT; i++)
    _action[i]->check();
  for (int i = 0; i < Action::COUNT; i++)
    if (_doing->allow(i) && _action[i]->request())
      {
	_doing = &_action[i];
	_doing->init();
      }
  _doing = _doing->step();
}

void		Player::hit(const Hit *hit)
{
  _hit = hit;
}

/*********/
/* SPEED */
/*********/
void		Player::sx(const Distance &s)
{
  _speed.xDist() = s;
}

void		Player::sy(const Distance &s)
{
  _speed.yDist() = s;
}

const Distance	&Player::sx() const
{
  return (_speed.xDist());
}

const Distance	&Player::sy() const
{
  return (_speed.yDist());
}

Position const	&Player::speed() const
{
  return (_speed);
}

/************/
/* POSITION */
/************/

int		Player::x()
{
  return (_pos.x());
}

int		Player::y()
{
  return (_pos.y());
}

Position const	&Player::pos() const
{
  return (_pos);
}

Bones			&bones();
