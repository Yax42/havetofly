//
// Math.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 00:57:09 2013 Brunier Jean
// Last update Sat Apr 13 17:22:36 2013 Brunier Jean
//

#ifndef MATH_HH_
# define MATH_HH_

# define MBIT_OS			10
# define MTO_FLOAT(x)			((x) << MBIT_OS)
# define MTO_INT(x)			((x) >> MBIT_OS)
# define MFLOAT_UNIT			(MTO_FLOAT(1))
# define MUL_FLOAT(x, y)		((x * y) >> MBIT_OS)
# define MPUT_IN(x, min, max)		((x <= min) ? min + 1 : ((x >= max) ? max - 1 : x))
# define MPOS(x)			((x < 0) ? -x : x)

# include <vector>

# include "Distance.hh"

class Math
{
private:
  static std::vector<Distance>	_cos;
  static std::vector<Distance>	_sin;
  static std::vector<Distance>	_tan;
  static std::vector<Distance>	_acos;
  static std::vector<Distance>	_asin;
  static std::vector<Distance>	_atan;
  static std::vector<long>	_sqrt;
  static std::vector<Distance>	_toRad;
  static std::vector<long>	_toDeg;
public:
  static const Distance		maxRad;

private:
  Math();
  Math(const Math &other);
  Math &operator=(const Math &other);
  ~Math();

public:
  static void		init();
  static Distance	cos(const Distance &v);
  static Distance	sin(const Distance &v);
  static Distance	tan(const Distance &v);
  static Distance	acos(const Distance &v);
  static Distance	asin(const Distance &v);
  static Distance	atan(const Distance &v);
  static Distance	sqrt(const Distance &d);
  static Distance	toRad(int deg);
  static int		toDeg(Distance const &rad);
};

#endif /* !MATH_HH_ */
