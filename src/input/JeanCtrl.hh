//
// JeanCtrl.hh for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 00:43:57 2013 Brunier Jean
// Last update Thu Apr 18 17:45:11 2013 Brunier Jean
//

#ifndef JEANCTRL_HH_
# define JEANCTRL_HH_

# include "Key.hh"

class JeanCtrl
{
private:
  int		_fd;
  int		_keys[Key::COUNT];
  char		_buf[30];
public:
  JeanCtrl();
  ~JeanCtrl();
  Key		getKey();
  void		proc();
  bool		isOk() const;
  void		update();
};

#endif /* !JEANCTRL_HH_ */
