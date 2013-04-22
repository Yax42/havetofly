//
// APrintable.hh for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 21 16:33:46 2013 Brunier Jean
// Last update Sun Apr 21 23:48:56 2013 Brunier Jean
//

#ifndef APRINTABLE_HH_
# define APRINTABLE_HH_

# include "Math.hh"
# include "Graphics.hh"
# include "Wait.hh"
# include "MyTime.hh"

class APrintable
{
protected:
  bool			_quit;
private:
  Wait			_wait;
public:
  APrintable(int fps);
  virtual ~APrintable(){}
  void			setPrint();
  bool			loop();
  void			quit();
  void			switchPrint(APrintable &next);
  virtual void		print(Graphics &g) = 0;

private:
  bool			cleanLoop(bool v);
  virtual bool		ifLoop();
  virtual void		initLoop();
  virtual void		endLoop();
  virtual bool		iterLoop() = 0;
};

#endif /* !APRINTABLE_HH_ */
