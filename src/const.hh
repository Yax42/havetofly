//
// const.hh for src in /home/brunie_j/local/my/havetofly/src
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Apr 13 20:56:35 2013 Brunier Jean
// Last update Sun Apr 21 00:52:05 2013 Brunier Jean
//

#ifndef CONST_HH_
# define CONST_HH_

	#define MAP_H	768
	#define MAP_W	1024
	#define BODY_SIZE	24 // 2/3
	extern const int	&DEBUG;

#define PLANE_DEBUG	((DEBUG & 32) != 0)
#define EASY_MODE ((DEBUG & 1024) != 0)

#endif /* !CONST_HH_ */
