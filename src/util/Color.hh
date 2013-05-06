//
// Color.hh for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Mon Apr 22 18:01:22 2013 Brunier Jean
// Last update Sun May 05 22:32:49 2013 Brunier Jean
//

#ifndef COLOR_HH_
# define COLOR_HH_

class Color
{
public:
  static const Color	RED;
  static const Color	YELLOW;
  static const Color	GREEN;
  static const Color	BLUE;
  static const Color	WHITE;
  static const Color	BLACK;
public:
  static const Color	fire[4];
public:
  int	r;
  int	g;
  int	b;

public:
  Color(int col);
  Color(int red, int green, int blue);
  ~Color(){}
  Color		&operator-=(Color const &col);
  Color		&operator+=(Color const &col);
  Color		operator+(Color const &col) const;
  Color		operator-(Color const &col) const;
  Color		operator-(int col) const;
  Color		operator*(int v) const;
  Color		operator/(int v) const;
  int		getInt() const;
};

#endif /* !COLOR_HH_ */
