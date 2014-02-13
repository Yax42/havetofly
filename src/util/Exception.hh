//
// Exception.hh for util in /home/brunie_j/local/my/havetofly/src/util
//
// Made by Brunier Jean
// Login	 <brunie_j@epitech.net>
//
// Started on	Sat Mar 23 11:47:29 2013 Brunier Jean
// Last update Wed Apr 17 16:57:54 2013 Brunier Jean
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
