//
// ThrowShuriken.hh for throw in /home/brunie_j/local/my/havetofly/src/action/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Tue Apr 23 11:58:23 2013 Brunier Jean
// Last update Tue Apr 23 23:38:31 2013 Brunier Jean
//

#ifndef THROWSHURIKEN_HH_
# define THROWSHURIKEN_HH_

# include "AAction.hh"

class ThrowShuriken : public AAction
{
private:
	const static int	_time;
	const static int	_timeMax;
public:
	ThrowShuriken(Player &player);
	virtual ~ThrowShuriken(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual IAction	*step();
	virtual void		set(int v = 0);
	virtual int		val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		check();
	virtual void		print(Graphics &g) const;
};

#endif /* !THROWSHURIKEN_HH_ */
