//
// Key.hh for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:21:14 2013 Brunier Jean
// Last update Wed Apr 17 20:44:18 2013 Brunier Jean
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
  int	operator[](int i);
  void	resetActKey();
  int	*&ptr(int i);
};

#endif /* !KEY_HH_ */
