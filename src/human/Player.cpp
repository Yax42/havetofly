//
// Player.cpp for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// THROW_BALL,
// Login   <brunie_j@epitech.net>
//
// Started on  Fri Apr 12 22:50:06 2013 Brunier Jean
// Last update Mon May 06 17:36:44 2013 Brunier Jean
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
Player::~Player()
{
  for (Throws i = _throwables.begin(); i != _throwables.end(); ++i)
    delete (*i);
}

Player::Player(const Position &pos, int team, const Key &k, int color) :
 	 _pos(pos), _alive(true), _team(team), _keys(k),
  	_color(color), key(_keys), _orient(1),
	_bones(_pos, _color, rand() % 0xFFFFFF, _orient),
	_mp(_speed, _pos, _event, _doing, this)
{
      _hit = NULL;
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

void		Player::tp(const Position &dir)
{
  _pos += dir;
  if (_pos.x() <= BODY_SIZE)
      _pos.x(BODY_SIZE);
  else if (_pos.x() >= Game::w() - BODY_SIZE)
      _pos.x(Game::w() - BODY_SIZE);
  if (_pos.y() <= BODY_SIZE)
      _pos.y(BODY_SIZE);
  else if (_pos.y() >= Game::h() + Game::deep)
      _pos.y(Game::h() + Game::deep);
}

/************/
/*  PROCESS */
/************/

void		Player::init()
{
  for (Throws i = _throwables.begin(); i != _throwables.end(); ++i)
    {
      if (!(*i)->isAlive())
        {
	  delete (*i);
	  i = _throwables.erase(i);
	}
      else
	  (*i)->init();
    }
  _mp.init();
  _action[IAction::HIT_LAGG]->check();
}

void		Player::move()
{
  if (_action[IAction::HIT_LAGG]->val() == 0)
    _mp.proc();
  for (Throws i = _throwables.begin(); i != _throwables.end(); ++i)
    if ((*i)->isAlive())
        (*i)->proc();
}

void		Player::procHit()
{
  int		tmp;

  if (_hit != NULL)
    {
      if (_hit->isThrowable())
	_event[Event::HIT_THROW] = true;
      else
	_event[Event::HIT] = true;
      tmp = _hit->go(*this);
      if (tmp != 0)
        {
	  _doing = _action[IAction::STUN];
	  if (tmp != -1)
	    _doing->init(tmp);
	}
      else if (!_hit->isThrowable())
        _doing = _action[IAction::INERTIE];
      _hit = NULL;
    }
}

void		Player::process()
{
  for (Throws i = _throwables.begin(); i != _throwables.end(); ++i)
    if ((*i)->isAlive())
      (*i)->move();
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
void	Player::doThrow(IThrowable *throwable)
{
  _throwables.push_back(throwable);
}

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
void		Player::sx(const Ratio &s)
{
  _speed.x(s);
}

void		Player::sy(const Ratio &s)
{
  _speed.y(s);
}

const Ratio	&Player::sx() const
{
  return (_speed.xRatio());
}

const Ratio	&Player::sy() const
{
  return (_speed.yRatio());
}

RatioPosition const	&Player::speed() const
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

const Bones	&Player::bones() const
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
int		Player::closeWall() const
{
  return ((_pos.x() > Game::w() / 2) ? 1 : -1);
}

Position	Player::closePos() const
{
  Player	*target = NULL;
  Distance	max(10000);

  for(Players::iterator i = Game::players().begin(); i != Game::players().end(); ++i)
    if (*i != this && (*i)->alive())
      if (_pos.distance((*i)->pos()) < max)
        {
	  max = _pos.distance((*i)->pos());
	  target = *i;
	}
  //std::cout << target->pos() << std::endl;
  if (target)
    return (target->pos() - _pos);
  else
    return (Position());
}

int		Player::color() const
{
  return (_color);
}

void		Player::print(Graphics &g)
{
  for (Throws i = _throwables.begin(); i != _throwables.end(); ++i)
    if ((*i)->isAlive())
      {
	if (DEBUG & 8)
          (*i)->printHB(g);
        (*i)->print(g);
      }
  _bones.print(g);
  for (int j = 0; j < IAction::COUNT; j++)
    _action[j]->print(g);
  if (DEBUG & 8)
      _doing->printHB(g);
}
