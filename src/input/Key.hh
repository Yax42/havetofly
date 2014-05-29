//
// Key.hh for input in /home/brunie_j/local/my/havetofly/src/input
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 14 01:21:14 2013 Brunier Jean
// Last update Mon May 06 22:20:11 2013 Brunier Jean
//

#ifndef KEY_HH_
# define KEY_HH_

# include <vector>
# include "Position.hh"

class Key
{
public:
	enum
		{
			HOR,
			VERT,
			HOR2,
			VERT2,
			L2,
			R2,
			A,
			X,
			Y,
			B,
			L,
			R,
			COUNT
		};
	enum
	{
		FIRST_ANALOG = HOR,
		LAST_ANALOG = VERT2,
		FIRST_BUTTON = L2,
	};
private:
	int					_prevVal[Key::COUNT];
	int					*_val[Key::COUNT];
	int					_delta[Key::COUNT];
	mutable Position	_lastOkDir[2];

public:
	Key();
	~Key(){}
	Angle			angle(int id = 0) const;
	Position		direction(int id = 0) const;
	int				operator[](int keyDown) const;
	int				getKeyDown(int i) const { return (*this)[i]; }
	int				operator()(int key) const;
	int				getKey(int i) const { return (*this)(i); }
	void			update();
	int				cur() const;
	int				*&ptr(int i);
	float			squaredLength() const;
	float			length() const;
};

#endif /* !KEY_HH_ */
