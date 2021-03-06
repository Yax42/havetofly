//
// Math.hh for math in /home/brunie_j/local/my/havetofly/src/math
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 10 00:57:09 2013 Brunier Jean
// Last update Sun Apr 28 00:05:54 2013 Brunier Jean
//

#ifndef MATH_HH_
# define MATH_HH_

# define MCAP(x, min, max)		((x <= min) ? (min) + 1 : ((x >= max) ? max - 1 : x))

# define MGRAD_CAP(x, min, scale)	(min + (((x) % ((scale) * 2) >= scale) ?	\
      					(scale) - ((x) % (scale)) - 1 :		\
				  	(x) % (scale)))

# define MPOS_MOD(x, y)			(((x) % (y) < 0) ? (x) % (y) + (y) : (x) % (y))
# define MRAND_POS_SQ(size)		(Position(rand() % (size * 2) - size, rand() % (size * 2) - size))

# define MRAND_POS_CI(size)		(Position(Angle(rand(), 0), rand() % size))

# define MPOS(x)			(((x) < 0) ? -(x) : (x))
//# define MSIGN(x)			(((x) > 0) ? 1 : (((x) < 0) ? -1 : 0))
# define MSIGN(x)			(((x) > 0) - ((x) < 0))
# define MSIGN_(x)			(((x) >= 0) - ((x) < 0))
# define MMAX(x, y)			(((x) > (y)) ? x : y)

//# define HALF_PI			(M_PI / 2)

class Angle;

class Math
{
public:
  static const float		maxRad;
  static const float		PiHalf;
  static const float		PiTwo;
  static const float		Pi;

public:
  static float		sqrt(float d);
  static float		toRad(float deg);
  static float		toDeg(float rad);
  static int		abs(int v);
  static float		abs(float v);


  /**TRIGO**/
  static float		cos(const Angle &v);
  static float		sin(const Angle &v);
  static float		tan(const Angle &v);
  static float		acos(const Angle &v);
  static float		asin(const Angle &v);
  static float		atan(const Angle &v);

  static float		cos(float v);
  static float		sin(float v);
  static float		tan(float v);
  static float		acos(float v);
  static float		asin(float v);
  static float		atan(float v);


private:
  Math();
  Math(const Math &other);
  Math &operator=(const Math &other);
  ~Math();
};

#endif /* !MATH_HH_ */
