//
// Key.hh for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sun Apr 14 01:21:14 2013 Brunier Jean
// Last update Mon May 06 22:20:11 2013 Brunier Jean
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
      X,
      Y,
      B,
      R,
      L,
      COUNT
    };
private:
  int		_prevVal[Key::COUNT];
  int		*_val[Key::COUNT];
  int		_delta[Key::COUNT];

public:
  Key();
  ~Key(){}
  int	operator[](int i) const;
  int	operator()(int i) const;
  void	update();
  int	cur() const;
  int	*&ptr(int i);
};

#endif /* !KEY_HH_ */
