/*
** IGraphics.hh for src in /home/brunie_j/local/nibbler/nibbler/src
**
** Made by Brunier Jean
** Login   <brunie_j@epitech.net>
**
** Started on  Mon Mar 04 15:55:09 2013 Brunier Jean
** Last update Sat Mar 16 22:09:03 2013 Brunier Jean
*/

#ifndef IGRAPHICS_HH_
# define IGRAPHICS_HH_

# include "Position.hh"
# include "Snake.hh"

class IGraphics
{
public:
  virtual void	rotCircle(Position const &first, int size, int color, std::list<Position> const &centers) = 0;
  virtual void	square(Position const &pos1, Position const &pos2, int color) = 0;
  virtual void	squareSpiral(Position pos1, Position pos2, int delta, int size, int color) = 0;
  virtual void	squareCeption(Position pos1, Position pos3, int delta, int size, int color) = 0;
  virtual void	triangleCeption(Position const &pos1, Position const &pos2, Position const &pos3, int delta, int size, int color) = 0;
  virtual void	star(Position const &center, int angle, int delta, int size, int color) = 0;

  virtual void	sponge(Position const &pos, int ray, int nb, int size, int angle, int color) = 0;
  virtual void	circle(Position const &pos, int size, int color) = 0;
  virtual void	line(Position const &pos1, Position const &pos2, int camber, int color) = 0;
  virtual void	spiral(Position const &pos, int angle, int delta, int size, int color) = 0;
  virtual void  spiral(Position const &pos, int angle, int delta, int size, long color1, long color2) = 0;
  virtual void	printScreen() = 0;
  virtual void	resetScreen(int color) = 0;
  virtual bool	checkEvent(Snake &s) = 0;
  virtual void	printPixel(Position const &pos, int color) = 0;
  virtual bool	isFinish() const = 0;
  virtual ~IGraphics() {}
};

#endif /* !IGRAPHICS_HH_ */
