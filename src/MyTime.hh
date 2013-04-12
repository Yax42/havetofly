/*
** Time.hh for src in /home/brunie_j/local/nibbler/nibbler/src
**
** Made by Brunier Jean
** Login   <brunie_j@epitech.net>
**
** Started on  Tue Mar 05 15:11:02 2013 Brunier Jean
** Last update Wed Mar 20 10:51:43 2013 Brunier Jean
*/

#ifndef TIME_HH_
# define TIME_HH_

class MyTime
{
  public:
    static int	_time;
    static void	run();
    static int	get();
    static void	reset();
};

#endif /* !TIME_HH_ */
