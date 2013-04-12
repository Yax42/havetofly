//
// Exception.cpp for src in /home/brunie_j/svn/nibbler/nibbler-2016-lu_a/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Sat Mar 23 11:47:21 2013 Brunier Jean
// Last update Sat Mar 23 12:08:20 2013 Brunier Jean
//

# include "Exception.hh"

Exception::Exception(std::string const &msg) throw(): _msg(msg)
{
}

Exception::Exception(const exception& e) throw(): _msg(e.what())
{
}

Exception& Exception::operator=(const Exception& e) throw()
{
  _msg = e.what();
  return (*this);
}

Exception::~Exception() throw()
{
}

const char*	Exception::what() const throw()
{
  return (_msg.c_str());
}
