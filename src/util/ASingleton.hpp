//
// ASingleton.hpp for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Wed Apr 17 15:41:22 2013 Brunier Jean
// Last update Wed Apr 17 16:25:40 2013 Brunier Jean
//

#ifndef ASINGLETON_HPP_
# define ASINGLETON_HPP_

template <class T>
class ASingleton
{
private:
  ASingleton();
protected:
  static T		*_inst;
public:
  static T		*get()
    {
      return (_inst);
    }

  static void		destroy()
    {
      if (_inst != NULL)
        {
  	  delete _inst;
	  _inst = NULL;
        }
    }
};

static T		*_inst = NULL;

#endif /* !ASINGLETON_HPP_ */
