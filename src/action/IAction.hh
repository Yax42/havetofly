//
// IAction.hh for action in /home/brunie_j/local/my/havetofly/src/action
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Wed Apr 10 20:19:08 2013 Brunier Jean
// Last update Sun May 05 21:48:38 2013 Brunier Jean
//

#ifndef IACTION_HH_
# define IACTION_HH_

# include <list>

class Hitbox;
class Player;
class Bones;
class Graphics;

class IAction
{
public:
	enum
		{
			INERTIE,
			GRAVITY,
			HIT_WALL,
			HIT_CEILING,
			HIT_LAGG,
			DEATH,
/*		*/  MOVE, /* ACTIVE STARTS HERE */
			STUN,
			TEMPO,
			DOUBLE_JUMP,
			TECH,
			STICK_CEILING,
			STICK_WALL,
			WALL_JUMP,
			THROW_SHURIKEN,
/* End of the cool list */
			SHIELD,
			AUTO_GUN,
			GUN_JUMP,
			THROW_BALL,
			EFFECTIVE_TV,
			TELEVISION,
			SPIN,
			HOR_TP,
			HOR_DASH,
			UP_PUNCH,
			DOWN_DASH,
			CURVE,
/*		  */COUNT, /* End of the list */
			DUMMY,
		};
	enum { FIRST_ACTIVE = MOVE}; // Is this durty?
	virtual ~IAction(){}
	virtual bool		allow(int a) = 0;
	virtual void		step() = 0;
	//virtual void		focus(Player &player) = 0;
	virtual bool		request() = 0;
	virtual void		init(int v = 0) = 0;
	virtual bool		hit(Player &ennemy) = 0;
	virtual void		check() = 0;
	virtual int			get(int) = 0;
	virtual int			val() = 0;
	virtual void		set(int val = 0) = 0;
	virtual int			id() const = 0;
	virtual bool		isActive() const = 0;
	virtual void		end() = 0;

	virtual const		std::list<Hitbox>	&getHB() const = 0;
	virtual void		upBones() = 0;
	virtual void		print(Graphics &g) const = 0;
	virtual void		printHB(Graphics &g) const = 0;
	virtual int			hitLagg() const = 0;
};

#endif /* !IACTION_HH_ */
