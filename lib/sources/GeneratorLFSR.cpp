#include "GeneratorLFSR.h"
#include <uchar.h>

GeneratorLFSR::GeneratorLFSR(char32_t polynomial, int polynomial_degree, char32_t seed) : m_polynomial(polynomial), m_polynomial_size(polynomial_degree - 1), m_state(seed)
{
   if (m_polynomial_size > sizeof(char32_t))
   {
      // Throw exception
   }

   char32_t mask = ~(char32_t)(0);
   mask = mask << m_polynomial_size;
   mask = ~mask;

   m_polynomial = m_polynomial & mask;
   m_state = m_state & mask;
}

char32_t GeneratorLFSR::generate(int number_of_bits)
{
   if (number_of_bits > sizeof(char32_t))
   {
      // Throw exception
   }

   char32_t data = 0;

   for (int i = 0; i < number_of_bits; i++)
   {
      data = (data << 1) | (m_state & 0x1);
      char32_t feedback = 0;

      for (int j = 0; j < m_polynomial_size; j++)
      {
         feedback = feedback ^ (((m_state >> j) & 0x1) & ((m_polynomial >> j) & 0x1));
      }

      m_state = (m_state >> 1) | (feedback << (m_polynomial_size - 2));
   }

   return data;
}
