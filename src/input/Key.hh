//
// Key.hh for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:21:14 2013 Brunier Jean
// Last update Sun Apr 14 18:40:47 2013 Brunier Jean
//

#ifndef KEY_HH_
# define KEY_HH_

# include <vector>

class Key
{
public:
  enum
    {
      HOR,
      VERT,
      A,
      B,
      X,
      Y,
      R,
      L,
      COUNT
    };
private:
  int		*_val[Key::COUNT];

public:
  Key();
  ~Key(){}
  int	*operator[](int i);
  int	*&ptr(int i);
};

#endif /* !KEY_HH_ */
