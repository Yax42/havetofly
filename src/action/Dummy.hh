//
// Made by Brunier Jean - 14/02/2014
//

#ifndef DUMMY_ACTION_HH_
# define DUMMY_ACTION_HH_

# include "PassiveAction.hh"

class DummyAction : public PassiveAction
{
public:
	DummyAction(Player &player) : PassiveAction(player, DUMMY) {}
	virtual ~DummyAction(){}
};

#endif /* !DUMMY_ACTION_HH_ */