//
// EffectiveTV.hh for b in /home/brunie_j/local/my/havetofly/src/action/active/b
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun May 05 20:57:39 2013 Brunier Jean
// Last update Tue May 07 00:47:33 2013 Brunier Jean
//

#ifndef EFFECTIVETV_HH_
# define EFFECTIVETV_HH_

# include <list>
# include "AAction.hh"

class EffectiveTV : public AAction
{
private:
  Position		_speed;
  const std::list<char>	*_paternPtr;
  std::list<char>	_patern;
  bool			_ok;

public:
  EffectiveTV(Player &player);
  virtual ~EffectiveTV(){}
  virtual void		init(int v = 0);
  virtual bool		allow(int a);
  virtual IAction	*step();
  virtual void		set(int v = 0);
  virtual void		setPatern(const std::list<char> &patern);
  virtual int		val();
  virtual bool		request();
  virtual void		upBones();
  virtual void		check();
  virtual void		print(Graphics &g) const;
};

#endif /* !EFFECTIVETV_HH_ */
