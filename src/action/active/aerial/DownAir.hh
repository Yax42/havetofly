#ifndef DOWN_AIR_HH_
# define DOWN_AIR_HH_

# include "AAction.hh"

class DownAir : public AAction
{
private:
	static const float				Power;
public:
	DownAir(Player &player);
	virtual ~DownAir(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual void		step();
	virtual void		check();
	virtual int			val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		print(Graphics &g) const;
};

#endif /* !DOWN_AIR_HH_ */