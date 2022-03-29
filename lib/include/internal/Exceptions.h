#ifndef _H_EXCEPT_
#define _H_EXCEPT_

#include <exception>

// LFSR and OTP with LFSR
struct IllegalPolynomialDegree : public std::exception
{
   const char *what() const throw()
   {
      return "Given polynomial degree is illegal";
   }
};

struct IllegalNumberOfBits : public std::exception
{
   const char *what() const throw()
   {
      return "Requested number of bits is illegal";
   }
};

#endif //_H_EXCEPT_
