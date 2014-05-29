#include "DownAir.hh"
#include "Game.hh"

const float				DownAir::Power = 15;

DownAir::DownAir(Player &player) :
AAction(player, DOWN_AIR, new Hit(60, Position(-Power, 0), player.orient(), 30, false, Hit::METEOR))
{
	_hit->add(24, Position(), _bones[Bones::FOOT1]);
	_hit->add(24, Position(), _bones[Bones::FOOT2]);
}

void	DownAir::init(int v)
{
	_hit->reset();
	_hit->sleep(true);
	_count = 70;
	_hit->setSpeed(Position(0, Power));
}

bool	DownAir::allow(int a)
{
	return (a == GRAVITY || a == INERTIE);
}

void	DownAir::step()
{
	_count--;
	if (_count == 25)
		_hit->sleep(false);

	if (_count == 0)
		_player.engageAction(INERTIE);
}

void		DownAir::check()
{
}

bool		DownAir::request()
{
	return _player.key.getKeyDown(Key::VERT2) == 1;
}

int			DownAir::val()
{
	return 0;
}

void		DownAir::upBones()
{
	int delta = 90 + (70 - _count) / 2;
	if (_count > 25)
	{
		_bones.set(delta, -delta, -delta, delta, delta, 0, -delta, 0, 0, 0);
	}
	else
		_bones.set(5, 10, -5, 5, 60, 0, -60, 0, 0, 0);
}

void		DownAir::print(Graphics &g) const
{
}