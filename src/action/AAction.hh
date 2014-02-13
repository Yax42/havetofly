//
// AAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 20:27:41 2013 Brunier Jean
// Last update Sun Apr 28 00:01:30 2013 Brunier Jean
//

#ifndef AACTION_HH_
# define AACTION_HH_

# include "IAction.hh"
# include "Player.hh"
# include "Hitbox.hh"
# include "MyTime.hh"
# include "Math.hh"
# include "Exception.hh"
# include "Key.hh"
# include "Color.hh"
# include "Graphics.hh"
# include "Bones.hh"
# include "const.hh"

class Hit;
class Player;

class AAction : public IAction
{
protected:
	Player		&_player;
	Hit			*_hit;
	int			_open;
	int			_count;
	Bones			&_bones;
	int			_id;
	std::list<Hitbox>	_hb;

public:
	virtual ~AAction();
	AAction(Player &player, int id, Hit *hit);
	virtual void		init(int v = 0);
	virtual bool		allow(int a);
	virtual IAction	*step();
	virtual bool		hit(Player &ennemy);
	virtual int		val();
	virtual void		set(int v = 0);
	virtual bool		request();
	virtual void		check();
	virtual const	std::list<Hitbox>	&getHB() const;
	virtual void		upBones();
	virtual int		id() const;
	virtual void		print(Graphics &g) const;
	virtual void		printHB(Graphics &g) const;
	virtual bool		isActive() const;
	virtual int		hitLagg() const;
	virtual void		loadBones();

};

#endif /* !AACTION_HH_ */
