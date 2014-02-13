//
// SetKeys.hh for menu in /home/brunie_j/local/my/havetofly/src/menu
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 21 00:59:22 2013 Brunier Jean
// Last update Sun Apr 21 19:59:14 2013 Brunier Jean
//

#ifndef SETKEYS_HH_
# define SETKEYS_HH_

# include "APrintable.hh"
# include <vector>

class SetKeys : public APrintable
{
private:
	std::vector<char *>	_paterns;
	int			_current;
	std::vector<int>	_ids;
public:
	SetKeys();
	~SetKeys(){}
private:
	bool		allGood() const;
	bool		isIn(std::vector<int> &ids, int v);
	virtual bool		iterLoop();
	virtual bool		ifLoop();
	virtual void		initLoop();
/* PRINTABLE */
public:
	virtual void		print(Graphics &g);

};

#endif /* !SETKEYS_HH_ */
