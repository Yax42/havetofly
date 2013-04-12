//
// Bones.hh for human in /home/brunie_j/local/my/havetofly/src/human
// // Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 16:06:02 2013 Brunier Jean
// Last update Wed Apr 10 17:37:00 2013 Brunier Jean
//

#ifndef BONES_HH_
# define BONES_HH_

# include "Position.hh"

class Charac;

class Bones
{
  const Charac		&_charac;
  Position		_foot1;
  Position		_foot2;
  Position		_hand1;
  Position		_hand2;
  Position		_hand2;
  Angle			_body;
  Angle			_head;

  Bones(Charac const &charac);
  ~Bones();
  void	foot1(Position const &pos);
  void	foot2(Position const &pos);
  void	hand1(Position const &pos);
  void	hand2(Position const &pos);
  void	body(Angle const &angle);
  void	head(Angle const &angle);
  //print
};

#endif /* !BONES_HH_ */
