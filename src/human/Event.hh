//
// Event.hh for human in /home/brunie_j/local/my/havetofly/src/human
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Fri Apr 19 22:31:48 2013 Brunier Jean
// Last update Thu Apr 25 23:26:57 2013 Brunier Jean
//

#ifndef EVENT_HH_
# define EVENT_HH_

namespace Event
{
	enum
		{
			FLOOR,
			CEILING,
			LEFT_WALL,
			RIGHT_WALL,
			WALL,
			DID_HIT,
			HIT,
			HIT_THROW,
			COUNT
		};
}

#endif /* !EVENT_HH_ */
