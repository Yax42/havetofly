//
// APrintable.hh for graphics in /home/brunie_j/local/my/havetofly/src/graphics
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sun Apr 21 16:33:46 2013 Brunier Jean
// Last update Sun Apr 21 23:48:56 2013 Brunier Jean
//

#ifndef APRINTABLE_HH_
# define APRINTABLE_HH_

# include "Math.hh"
# include "Graphics.hh"
# include "Wait.hh"
# include "MyTime.hh"
# include "ALoop.hh"

class APrintable : public ALoop
{
public:
	APrintable(int fps);
	virtual ~APrintable(){}
	void			setPrint();
	bool			actualLoop();
	void			switchPrint(APrintable &next);
	virtual void	print(Graphics &g) = 0;

private:
	bool			cleanLoop(bool v);
};

#endif /* !APRINTABLE_HH_ */
