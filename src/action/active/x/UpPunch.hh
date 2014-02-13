//
// UpPunch.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 20 19:47:13 2013 Brunier Jean
// Last update Sun Apr 28 15:57:36 2013 Brunier Jean
//

#ifndef UPPUNCH_HH_
# define UPPUNCH_HH_

# include "AAction.hh"

class UpPunch : public AAction
{
public:
	UpPunch(Player &player);
	virtual ~UpPunch(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual IAction	*step();
	virtual int		val();
	virtual void		set(int);
	virtual bool		request();
	virtual void		upBones();
	virtual void		check();
	virtual void		print(Graphics &g) const;
	virtual void		loadBones();
};

#endif /* !UPPUNCH_HH_ */
