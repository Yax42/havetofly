//
// Controler.hh for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Thu Apr 18 17:34:25 2013 Brunier Jean
// Last update Tue May 07 00:04:20 2013 Brunier Jean
//

#ifndef CONTROLER_HH_
# define CONTROLER_HH_

# include "Key.hh"

class Controler
{
private:
	int			_id;
	int			_fd;
	std::vector<int>	_axe;
	std::vector<int>	_but;
	char			_patern[8];
	int			_lastBut;
	char			_name[80];
	int			_null;

public:
	~Controler();
	Controler(int id);
	void		proc();
	Key		getKey();
	bool		isOk() const;
	void		update();
	bool		didAct();
	int		getLastBut();
	char		*getPatern();
	void		saveKey() const;
};


#endif /* !CONTROLER_HH_ */
