//
// SetKeys.cpp for menu in /home/brunie_j/local/my/havetofly/src/menu
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 21 01:00:26 2013 Brunier Jean
// Last update Mon May 06 23:40:48 2013 Brunier Jean
//

#include "SetKeys.hh"
#include "Input.hh"

SetKeys::SetKeys() : APrintable(120)
{
}

bool	SetKeys::allGood() const
{
	for (unsigned long i = 0; i < _paterns.size(); i++)
		if (_paterns[i][_current] == -1)
			return (false);
	return (true);
}

bool	SetKeys::isIn(std::vector<int> &_ids, int v)
{
	for (unsigned long i = 0; i < _ids.size(); i++)
		if (_ids[i] == v)
			return (true);
	return (false);
}

void	SetKeys::initLoop()
{
	_current = 0;
	for (int i = 0; i < NB_CTRL; i++)
		Input_.getLastBut(i);
	Input_.update();
}

bool	SetKeys::ifLoop()
{
	return (_current < 8);
}

bool	SetKeys::iterLoop()
{
	if (_current == 0)
		{
			for (int i = 0; i < NB_CTRL; i++)
	if (Input_.getLastBut(i) != -1 && !isIn(_ids, i))
		{
			_ids.push_back(i);
			_paterns.push_back(Input_.getPatern(i));
		}
			 if (Input_[SDLK_RETURN])
	 _current = 1;
		}
	if (_current == 1)
		{
			for (int i = 2; i < 8; i++)
				for (unsigned long j = 0; j < _ids.size(); j++)
					_paterns[j][i] = -1;
			 _current = 2;
		}
	if (_current >= 2)
		{
			for (unsigned long j = 0; j < _paterns.size(); j++)
	if (_paterns[j][_current] == -1)
		_paterns[j][_current] = Input_.getLastBut(_ids[j]);
			if (allGood())
	_current++;
		}
	if (_current == 8)
		for (unsigned long j = 0; j < _paterns.size(); j++)
			Input_.saveKey(_ids[j]);
	return (true);
}

/*********/
/* PRINT */
/*********/
void	SetKeys::print(Graphics &g)
{
	static Position center(g.h() / 2, g.w() / 2 + 80);
	static const int colors[] =
		{
			0xFFFFAA,
			0xCC0000,
			0x0000FF
		};
	g.resetScreen(0xaaee00 | MGRAD_CAP(MTIME / 10, 0, 255));
	g.rectangleFull(center + Position(-55, -260), center + Position(60, 60), colors[0]);
	for (int i = 0; i < 4; i++)
		{
			g.circleFull(Position((i == 0 ? 30 : (i == 2 ? -30 : 0)),
	 				(i == 1 ? -30 : (i == 3 ? 30 : 0))) + center, 15,
			 colors[_current == i + 2]);
			g.circleLaid(Position((i == 0 ? 30 : (i == 2 ? -30 : 0)),
	 				(i == 1 ? -30 : (i == 3 ? 30 : 0))) + center, 15,
			 colors[2]);
		}
	g.rectangleLaid(center + Position(-55, -260), center + Position(60, 60), colors[2]);

	g.rectangleFull(center + Position(-90, -40), center + Position(-60, 40), colors[_current == 6]);
	g.rectangleFull(center + Position(-90, -200), center + Position(-60, -120), colors[_current == 7]);

	g.rectangleLaid(center + Position(-90, -40), center + Position(-60, 40),
		 colors[2]);
	g.rectangleLaid(center + Position(-90, -200), center + Position(-60, -120),
		 colors[2]);

	for (unsigned long j = 0; j < _paterns.size(); j++)
		g.circleFull(Position(300, 100 +int(20 + j * 30)), 25, colors[_paterns[j][_current] != -1]);
}
