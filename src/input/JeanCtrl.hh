//
// JeanCtrl.hh for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 00:43:57 2013 Brunier Jean
// Last update Wed Apr 17 01:39:34 2013 Brunier Jean
//

#ifndef JEANCTRL_HH_
# define JEANCTRL_HH_

# include "Key.hh"

class JeanCtrl
{
private:
  int		_fd;
  int		_trueK[Key::COUNT];
  int		_fakeK[Key::COUNT];
  char		_buf[30];
public:
  JeanCtrl();
  ~JeanCtrl();
  Key		getKey();
  void		proc();
  bool		isOk() const;
  void		update();
private:
  void		setVal(int idx, bool);
};

#endif /* !JEANCTRL_HH_ */
