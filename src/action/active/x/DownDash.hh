//
// DownDash.hh for active in /home/brunie_j/local/my/havetofly/src/action/active
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 17 20:37:35 2013 Brunier Jean
// Last update Fri Apr 19 13:54:54 2013 Brunier Jean
//

#ifndef DOWNDASH_HH_
# define DOWNDASH_HH_

# include "AAction.hh"

class DownDash : public AAction
{
private:
	float					_shurikenCancel;
	Angle				_graphicAngle;
public:
	DownDash(Player &player);
	virtual ~DownDash(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual void		step();
	virtual void		check();
	virtual int			val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		print(Graphics &g) const;
	bool				checkShurikenCancel();
	void				updateSpeed();
};

#endif /* !DOWNDASH_HH_ */
