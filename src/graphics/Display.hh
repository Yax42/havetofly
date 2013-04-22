//
// Display.hh for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 14:43:41 2013 Brunier Jean
// Last update Sun Apr 21 19:54:14 2013 Brunier Jean
//

#ifndef DISPLAY_HH_
# define DISPLAY_HH_

# include "Graphics.hh"
# include "ALoop.hh"

class Mutex;
class APrintable;

class Display : public ALoop
{
private:
  static Mutex		mutex;
  static APrintable	*_target;
private:
  Graphics	_g;
public:
  virtual ~Display(){}
  Display(int h, int w);

  static void	setTarget(APrintable *target);
/* LOOP */
private:
  void		print();
  void		printBG();
  virtual void	initLoop();
  virtual void	endLoop();
  virtual bool	ifLoop();
  virtual bool	iterLoop();
};

#endif /* !DISPLAY_HH_ */
