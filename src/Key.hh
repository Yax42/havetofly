//
// Key.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:21:14 2013 Brunier Jean
// Last update Sun Apr 14 01:57:12 2013 Brunier Jean
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
  std::vector<int *>		_val;

public:
  Key();
  ~Key(){}
  int	&operator[](int i);
};

#endif /* !KEY_HH_ */
