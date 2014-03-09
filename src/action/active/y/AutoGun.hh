//
// AutoGun.hh for throw in /home/brunie_j/local/my/havetofly/src/action/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 27 22:33:56 2013 Brunier Jean
// Last update Sat Apr 27 23:16:07 2013 Brunier Jean
//

#ifndef AUTOGUN_HH_
# define AUTOGUN_HH_

# include "AAction.hh"

class AutoGun : public AAction
{
private:
	Angle			_angle;
	int			_sign;
public:
	AutoGun(Player &player);
	virtual ~AutoGun(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual void		step();
	virtual void		set(int v = 0);
	virtual int			val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		check();
	virtual void		print(Graphics &g) const;
};

#endif /* !AUTOGUN_HH_ */
