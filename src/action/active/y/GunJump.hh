//
// GunJump.hh for throw in /home/brunie_j/local/my/havetofly/src/action/throw
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 28 18:10:14 2013 Brunier Jean
// Last update Sun Apr 28 18:15:22 2013 Brunier Jean
//

#ifndef GUNJUMP_HH_
# define GUNJUMP_HH_

# include "AAction.hh"

class GunJump : public AAction
{
public:
	GunJump(Player &player);
	virtual ~GunJump(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual void		step();
	virtual void		set(int v = 0);
	virtual int		val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		check();
	virtual void		print(Graphics &g) const;
};

#endif /* !GUNJUMP_HH_ */
