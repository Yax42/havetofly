//
// AGraphics.hh for src in /home/brunie_j/svn/nibbler/nibbler-2016-lu_a/src
//
// Made by sebastien berton
// Login   <berton_s@epitech.net>
//
/* Started on  Tue Mar  5 17:57:15 2013 sebastien berton
** Last update Sat Mar 16 22:09:17 2013 Brunier Jean
*/

#ifndef	AGRAPHICS_HH_
# define AGRAPHICS_HH_

# include <cmath>

# include "IGraphics.hh"
# include "Position.hh"
# include "Exception.hh"
# include "MyTime.hh"
# include "Const.hh"

class AGraphics : public IGraphics
{
protected:
  bool	_isFinish;

public:
  AGraphics();
  virtual ~AGraphics();
  virtual void	rotCircle(Position const &first, int size, int color, std::list<Position> const &centers);
  virtual void  square(Position const &pos1, Position const &pos2, int color);
  virtual void	squareSpiral(Position pos1, Position pos2, int delta, int size, int color);
  virtual void	squareCeption(Position pos1, Position pos3, int delta, int size, int color);
  virtual void	triangleCeption(Position const &pos1, Position const &pos2, Position const &pos3, int delta, int size, int color);
  virtual void  line(Position const &pos1, Position const &pos2, int camber, int color);
  virtual void	star(Position const &center, int angle, int delta, int size, int color);

  virtual void	sponge(Position const &pos, int ray, int nb, int size, int angle, int color);
  virtual void  circle(Position const &pos, int size, int color);
  virtual void  spiral(Position const &pos, int angle, int delta, int size, int color);
  virtual void  spiral(Position const &pos, int angle, int delta, int size, long color1, long color2);
  virtual void	printScreen() = 0;
  virtual void  resetScreen(int color) = 0;
  virtual bool  checkEvent(Snake &s) = 0;
  virtual void	printPixel(Position const &pos, int color) = 0;
  virtual bool	isFinish() const;
private:
  void		privateTriangleCeption(Position const &pos1, Position const &pos2, Position const &pos3, int delta, int size, int color);

};

#endif	/* !AGRAPHICS_HH_ */
