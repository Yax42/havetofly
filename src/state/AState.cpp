//
// AState.cpp for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 17:06:24 2013 Brunier Jean
// Last update Wed Apr 10 17:28:08 2013 Brunier Jean
//

AState::Astate(Bones &b, const Position &topL, const Position &botR, const Position &center) :
	_hb(topL, botR, center), _bones(b)
{
}

AState::~AState()
{
}

bool	AState::touch(const Hitbox &other) const
{
  return (_hb.touch(other));
}
