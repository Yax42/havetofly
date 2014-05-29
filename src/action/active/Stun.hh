//
// Stun.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 23:22:45 2013 Brunier Jean
// Last update Tue Apr 23 15:58:34 2013 Brunier Jean
//

#ifndef STUN_HH_
# define STUN_HH_

# include "AAction.hh"

class Stun : public AAction
{
public:
	enum
	{
		RESET_TIME = -1,
		METEOR_LOCKED = -2,
		METEOR = -3,
		ADDITIVE = -5,
		NORMAL_STUN = -4,
	};
private:
	bool				_meteorCancel;
	int					_state;
public:
	Stun(Player &player);
	virtual ~Stun(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual void		step();
	virtual int		val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		set(int val = 0);
	virtual void		print(Graphics &g) const;
};


#endif /* !STUN_HH_ */
