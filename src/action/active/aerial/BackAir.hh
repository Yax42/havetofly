//
// BackAir.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 20:37:35 2013 Brunier Jean
// Last update Fri Apr 19 13:54:54 2013 Brunier Jean
//

#ifndef BACK_AIR_HH_
# define BACK_AIR_HH_

# include "AAction.hh"

class BackAir : public AAction
{
private:
	static const float				Power;
public:
	BackAir(Player &player);
	virtual ~BackAir(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual void		step();
	virtual void		check();
	virtual int			val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		print(Graphics &g) const;
};

#endif /* !BACK_AIR_HH_ */