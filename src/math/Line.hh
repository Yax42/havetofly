//
// Line.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 14 12:27:41 2013 Brunier Jean
// Last update Sun Apr 14 12:30:36 2013 Brunier Jean
//

#ifndef LINE_HH_
# define LINE_HH_

# include "Position.hh"

class Line
{
private:
	/*Distance	_a;
	Distance	_b;*/

public:
	~Line(){}
	Line(const Position &p1, const Position &p2);
	Position	operator==(const Line &other) const;
};

#endif /* !LINE_HH_ */
