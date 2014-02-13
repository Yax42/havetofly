//
// Curve.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 25 23:49:42 2013 Brunier Jean
// Last update Thu Apr 25 23:50:21 2013 Brunier Jean
//

#ifndef CURVE_HH_
# define CURVE_HH_

# include "AAction.hh"

class Curve : public AAction
{
public:
	Curve(Player &player);
	virtual ~Curve(){}
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

#endif /* !CURVE_HH_ */
