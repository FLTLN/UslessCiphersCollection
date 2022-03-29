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

// Encryption and decryption with CipherShift, CipherSimpleSubstitution and CipherVigenere
struct SymbolNotInAlphabet : public std::exception
{
   const char * what () const throw ()
   {
      return "Symbol in input string does not found in alphabet";
   }
};

// Encryption and decryption with One Time Pad
struct InsufficientKeystream : public std::exception
{
   const char * what () const throw ()
   {
      return "Keystream length is less than input string length";
   }
};

#endif //_H_EXCEPT_
