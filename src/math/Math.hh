//
// Math.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 00:57:09 2013 Brunier Jean
// Last update Mon Apr 15 14:45:30 2013 Brunier Jean
//

#ifndef MATH_HH_
# define MATH_HH_

# define MBIT_OS			10
# define MBIT_OS_RATIO			20
# define MTO_RATIO(x)			((x) << MBIT_OS_RATIO)
# define MTO_FLOAT(x)			((x) << MBIT_OS)
# define MTO_INT(x)			((x) >> MBIT_OS)
# define MFLOAT_UNIT			(MTO_FLOAT(1))
# define MRATIO_UNIT			(MTO_RATIO(1))
# define MUL_FLOAT(x, y)		((x * y) >> MBIT_OS)
# define MPUT_IN(x, min, max)		((x <= min) ? min + 1 : ((x >= max) ? max - 1 : x))
# define MPOS(x)			(((x) < 0) ? -(x) : (x))

# include <vector>

# include "Ratio.hh"
# include "Distance.hh"

class Math
{
private:
  static std::vector<Ratio>	_cos;
  static std::vector<Ratio>	_sin;
  static std::vector<Ratio>	_tan;
  static std::vector<Ratio>	_acos;
  static std::vector<Ratio>	_asin;
  static std::vector<Ratio>	_atan;
  static std::vector<long>	_sqrt;
  static std::vector<Ratio>	_toRad;
  static std::vector<long>	_toDeg;
public:
  static const Ratio		maxRad;

private:
  Math();
  Math(const Math &other);
  Math &operator=(const Math &other);
  ~Math();

public:
  static void		init();
  static Ratio		cos(const Ratio &v);
  static Ratio		sin(const Ratio &v);
  static Ratio		tan(const Ratio &v);
  static Ratio		acos(const Ratio &v);
  static Ratio		asin(const Ratio &v);
  static Ratio		atan(const Ratio &v);
  static Distance	sqrt(const Distance &d);
  static Ratio		toRad(int deg);
  static int		toDeg(Ratio const &rad);
};

#endif /* !MATH_HH_ */
