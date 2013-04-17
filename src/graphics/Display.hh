//
// Display.hh for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 14:43:41 2013 Brunier Jean
// Last update Wed Apr 17 15:11:17 2013 Brunier Jean
//

#ifndef DISPLAY_HH_
# define DISPLAY_HH_

# include "Graphics.hh"
# include "ALoop.hh"

class Display : public ALoop
{
private:
  Graphics	_g;
public:
  virtual ~Display(){}
  Display(int h, int w);
private:
  virtual void	initLoop();
  virtual void	endLoop();
  virtual bool	ifLoop();
  virtual bool	iterLoop();
};

#endif /* !DISPLAY_HH_ */
