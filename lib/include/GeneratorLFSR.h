#ifndef _H_LFSR_
#define _H_LFSR_

#include <uchar.h>

class GeneratorLFSR
{
public:
   GeneratorLFSR(char32_t polynomial, int polynomial_degree, char32_t seed);
   char32_t generate(int number_of_bits);

private:
   char32_t m_polynomial, m_state;
   int m_polynomial_size;
};

#endif //_H_LFSR_
