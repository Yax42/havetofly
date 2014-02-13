//
// HorTP.hh for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun May 05 18:44:20 2013 Brunier Jean
// Last update Mon May 06 23:47:23 2013 Brunier Jean
//

#ifndef HORTP_HH_
# define HORTP_HH_

# include "AAction.hh"

class HorTP : public AAction
{
private:
	Position		_pos;
public:
	HorTP(Player &player);
	virtual ~HorTP(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual IAction	*step();
	virtual void		set(int);
	virtual bool		request();
	virtual void		upBones();
	virtual void		check();
	virtual void		print(Graphics &g) const;
};

#endif /* !HORTP_HH_ */
