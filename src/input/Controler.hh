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
#ifdef UNIX
	#include <linux/joystick.h>
#endif


class Controler
{
private:
#ifdef UNIX
	js_event		_event;
	int			_fd;
#endif
	static int			Null;
	int					_id;
	int					_keys[Key::COUNT];

	SDL_Joystick		*_joystick; // on crée le joystick

public:
	~Controler();
	Controler(int id);
	void		proc();
	Key			getKey();
	bool		isOk() const;
	void		update();
	bool		didAct();
	int			getLastBut();
	char		*getPatern();
	void		saveKey() const;
	void		clean();
};


#endif /* !CONTROLER_HH_ */
