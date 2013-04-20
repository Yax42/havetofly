//
// Controler.hh for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 18 17:34:25 2013 Brunier Jean
// Last update Thu Apr 18 20:55:40 2013 Brunier Jean
//

#ifndef CONTROLER_HH_
# define CONTROLER_HH_

# include "Key.hh"

class Controler
{
private:
  struct JsEvent
  {
    unsigned int time;      /* event timestamp in milliseconds */
    short value;	    /* value */
    unsigned char type;     /* event type */
    unsigned char number;   /* axis/button number */
  };

  JsEvent		_event;
  int			_id;
  int			_fd;
  std::vector<int>	_axe;
  std::vector<int>	_but;

public:
  ~Controler();
  Controler(int id);
  void		proc();
  Key		getKey();
  bool		isOk() const;
  void		update();
  bool		didAct();
};


#endif /* !CONTROLER_HH_ */