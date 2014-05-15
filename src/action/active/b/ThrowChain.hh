//
// ThrowChain.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on Fri Apr 19 13:54:54 2014 Brunier Jean
// Last update Fri Apr 19 13:54:54 2014 Brunier Jean
//

#ifndef THROW_CHAIN_HH_
# define THROW_CHAIN_HH_

# include "AAction.hh"

class ThrowChain : public AAction
{
private:
	Angle					_graphicAngle;
	bool					_usable;
public:
	ThrowChain(Player &player);
	virtual ~ThrowChain(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual void		step();
	virtual void		check();
	virtual int			val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		print(Graphics &g) const;
};

#endif /* !CHAIN_HH_ */