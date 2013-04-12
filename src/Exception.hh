//
// Exception.hh for src in /home/brunie_j/svn/nibbler/nibbler-2016-lu_a/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Mar 23 11:47:29 2013 Brunier Jean
// Last update Sat Mar 23 12:06:42 2013 Brunier Jean
//

#ifndef EXCEPTION_HH_
# define EXCEPTION_HH_

# include <exception>
# include <string>

class Exception : public std::exception
{
  private:
    std::string		_msg;
  public:
    Exception(std::string const &msg) throw();
    Exception(const exception&) throw();
    Exception& operator=(const Exception&) throw();
    virtual ~Exception() throw();
    virtual const char* what() const throw();
};

#endif /* !EXCEPTION_HH_ */
