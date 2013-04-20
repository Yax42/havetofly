//
// Player.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 22:50:06 2013 Brunier Jean
// Last update Fri Apr 19 22:53:23 2013 Brunier Jean
//

#include <cstdlib>
#include <algorithm>

#include "ActionFactory.hh"
#include "Player.hh"
#include "const.hh"
#include "Game.hh"

#include <iostream>

/****************/
/* CONSTRUCTORS */
/****************/
Player::~Player(){}

Player::Player(const Position &pos, int team, const Key &k) :
 	 _pos(pos), _alive(true), _team(team), _keys(k), key(_keys),
	_orient(1), _bones(_pos, 0xFF << (team * 8), rand() % 0xFFFFFF, _orient),
	_mp(_speed, _pos, _event, _doing)
{
  _event.resize(Event::COUNT);
  _action.resize(IAction::COUNT);
  for (int i = 0; i < IAction::COUNT; i++)
    _action[i] = ActionFactory::get(i, *this);
  _doing = _action[IAction::INERTIE];
}

/*************/
/*  OPEARTOS */
/*************/
void	Player::operator=(Position const &speed)
{
  _speed = speed;
}

int		Player::operator()(int event)
{
  return (_event[event]);
}

/*
int		Player::key(int k)
{
  return (_keys[k]);
}
*/

void		Player::orient(int o)
{
  _orient = o;
}

/************/
/*  PROCESS */
/************/

void		Player::init()
{
  _mp.init();
  _hit = NULL;
}

void		Player::move()
{
  _mp.proc();
}

void		Player::process()
{
  int		tmp;

  if (_hit != NULL)
    {
      _event[Event::HIT] = true;
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
  _doing->upBones();
}

void		Player::upKeys()
{
  _keys.update();
}

void		Player::hit(const Hit *hit)
{
  _hit = hit;
}

/**********/
/* ACTION */
/**********/
void	Player::setAction(int id, int initVal)
{
  _doing = _action[id];
  _doing->init(initVal);
}

int	Player::currentAction() const
{
  return (_doing->id());
}

IAction		*Player::operator[](int a)
{
  return (_action[a]);
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

const std::list<Hitbox>		&Player::getHB() const
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

const int	&Player::orient() const
{
  return (_orient);
}

int	Player::team() const
{
  return (_team);
}

