//
// Math.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 00:57:09 2013 Brunier Jean
// Last update Wed Apr 10 12:21:09 2013 Brunier Jean
//

#ifndef MATH_HH_
# define MATH_HH_

# define MBIT_OS			16
# define MTO_FLOAT(x)			((x) << MBIT_OS)
# define MTO_INT(x)			((x) >> MBIT_OS)
# define MFLOAT_UNIT			(MTO_FLOAT(1))
# define MUL_FLOAT(x, y)		(((x >> 6) * (y >> 6)) >> 4)
# define MPUT_IN(x, min, max)		((x <= min) ? min + 1 : ((x >= max) ? max - 1 : x))
# define MPOS(x)			((x < 0) ? -x : x)

# include <vector>

# include "Distance.hh"

class Math
{
private:
  static std::vector<long>	_cos;
  static std::vector<long>	_sin;
  static std::vector<long>	_tan;
  static std::vector<long>	_acos;
  static std::vector<long>	_asin;
  static std::vector<long>	_atan;
  static std::vector<int>	_sqrt;
  static std::vector<long>	_toRad;
  static std::vector<long>	_toDeg;
  static long		_maxRad;

private:
  Math();
  Math(const Math &other);
  Math &operator=(const Math &other);
  ~Math();

public:
  static void		init();
  static long		cos(long a);
  static long		sin(long a);
  static long		tan(long a);
  static long		acos(long v);
  static long		asin(long v);
  static long		atan(long v);
  static Distance	sqrt(const Distance &d);
  static long		toRad(int deg);
  static int		toDeg(long rad);
};

#endif /* !MATH_HH_ */
