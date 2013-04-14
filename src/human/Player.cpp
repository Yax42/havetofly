//
// Player.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 22:50:06 2013 Brunier Jean
// Last update Sun Apr 14 15:41:00 2013 Brunier Jean
//

#include <cstdlib>
#include <algorithm>

#include "ActionFactory.hh"
#include "Player.hh"
#include "const.hh"
#include "Game.hh"

/****************/
/* CONSTRUCTORS */
/****************/
Player::~Player(){}

Player::Player(const Position &pos, int team, const Key &k) : _pos(pos), _team(team), _keys(k),
	_orient(1), _bones(_pos, 0xFF << (team * 8), rand() % 0xFFFFFF, _orient)
{
  for (int i = 0; i < IAction::COUNT; i++)
    _action.push_back(ActionFactory::get(i, *this));
  _doing = _action[IAction::INERTIE];
}

/*************/
/*  OPEARTOS */
/*************/
void	Player::operator++()
{
  if (_speed.yDist() > -10)
    _speed.yDist() -= 0.1;
}

void	Player::operator=(Position const &speed)
{
  _speed = speed;
}

IAction		*Player::operator[](int a)
{
  return (_action[a]);
}

int		Player::operator()(int event)
{
  return (_event[event]);
}

int		&Player::key(int k)
{
  return (_keys[k]);
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
  if (_pos.x() <= BODY_SIZE)
    {
      _pos.x(BODY_SIZE);
      _event[Event::LEFT_WALL] = true;
      _event[Event::WALL] = true;
    }
  else if (_pos.x() >= Game::w() - BODY_SIZE)
    {
      _pos.x(Game::w() - BODY_SIZE);
      _event[Event::RIGHT_WALL] = true;
      _event[Event::WALL] = true;
    }
  if (_pos.y() <= BODY_SIZE)
    {
      _pos.y(BODY_SIZE);
      _event[Event::CEILING] = true;
    }
  else if (_pos.y() >= Game::h() - BODY_SIZE)
    {
      _pos.y(Game::h() - BODY_SIZE);
      _event[Event::FLOOR] = true;
    }
  for (Players::iterator i = Game::players.begin(); i != Game::players.end(); ++i)
    _doing->hit(&(*i));
}

void		Player::process()
{
  int		tmp;
  if (_hit != NULL)
    {
      tmp = _hit->go(*this);
      if (tmp > 0)
        {
	  _doing = _action[IAction::STUN];
	  _doing->init(tmp);
	}
      else
        _doing = _action[IAction::INERTIE];
    }
  for (int i = 0; i < IAction::COUNT; i++)
    _action[i]->check();
  for (int i = 0; i < IAction::COUNT; i++)
    if (_doing->allow(i) && _action[i]->request())
      {
	_doing = _action[i];
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
int		Player::x() const
{
  return (_pos.x());
}

int		Player::y() const
{
  return (_pos.y());
}

Position const	&Player::pos() const
{
  return (_pos);
}

/***********/
/* GETTERS */
/***********/
Bones		&Player::bones()
{
  return (_bones);
}

Player::operator const Hitbox() const
{
  return (_doing->getHB());
}

void	Player::kill()
{
  _alive = false;
}

bool	Player::alive() const
{
  return (_alive);
}

int	Player::team() const
{
  return (_team);
}
