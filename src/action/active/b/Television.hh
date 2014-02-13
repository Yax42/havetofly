//
// Television.hh for x in /home/brunie_j/local/my/havetofly/src/action/active/x
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun May 05 19:28:46 2013 Brunier Jean
// Last update Sun May 05 22:57:19 2013 Brunier Jean
//

#ifndef TELEVISION_HH_
# define TELEVISION_HH_

# include <list>
# include "AAction.hh"

class Television : public AAction
{
public:
	static const int	size;
private:
	bool			_didHit;
	std::list<char>	_patern;
public:
	Television(Player &player);
	virtual ~Television(){}
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual IAction	*step();
	virtual void		set(int v = 0);
	virtual int		val();
	virtual bool		request();
	virtual void		upBones();
	virtual void		check();
	virtual void		print(Graphics &g) const;
	virtual bool		hit(Player &ennemy);
};

#endif /* !TELEVISION_HH_ */
