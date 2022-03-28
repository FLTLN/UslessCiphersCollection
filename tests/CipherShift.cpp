#include "CipherShift.h"
#include "internal/Exceptions.h"

CipherShift::CipherShift(char *alphabet, int alphabet_len, int shift) : m_alphabet_len(alphabet_len), m_shift(shift)
{
   m_alphabet = new char[m_alphabet_len];
   for (size_t i = 0; i < m_alphabet_len; i++)
   {
      m_alphabet[i] = alphabet[i];
   }
}

CipherShift::~CipherShift()
{
   delete[] m_alphabet;
}

void CipherShift::encrypt(char *out, char *in, int in_length)
{
   for (size_t symbol_index = 0; symbol_index < in_length; symbol_index++)
   {

      size_t input_symbol_in_alphabet_index = m_alphabet_len + 1;

      for (size_t alphabet_symbol_index = 0; alphabet_symbol_index < m_alphabet_len; alphabet_symbol_index++)
      {
         if (in[symbol_index] == m_alphabet[alphabet_symbol_index])
         {
            input_symbol_in_alphabet_index = alphabet_symbol_index;
         }
      }

      if (input_symbol_in_alphabet_index > m_alphabet_len)
      {
         // Throw exception here
      }

      int output_symbol_in_alphabet_index = (int)input_symbol_in_alphabet_index + m_shift;

      if (output_symbol_in_alphabet_index < 0)
      {
         output_symbol_in_alphabet_index = m_alphabet_len + output_symbol_in_alphabet_index;
      }
      if (output_symbol_in_alphabet_index >= m_alphabet_len)
      {
         output_symbol_in_alphabet_index = output_symbol_in_alphabet_index - m_alphabet_len;
      }

      out[symbol_index] = m_alphabet[output_symbol_in_alphabet_index];
   }
}

void CipherShift::decrypt(char *out, char *in, int in_length)
{
   for (size_t symbol_index = 0; symbol_index < in_length; symbol_index++)
   {

      size_t input_symbol_in_alphabet_index = m_alphabet_len + 1;

      for (size_t alphabet_symbol_index = 0; alphabet_symbol_index < m_alphabet_len; alphabet_symbol_index++)
      {
         if (in[symbol_index] == m_alphabet[alphabet_symbol_index])
         {
            input_symbol_in_alphabet_index = alphabet_symbol_index;
         }
      }

      if (input_symbol_in_alphabet_index > m_alphabet_len)
      {
         // Throw exception here
      }

      int output_symbol_in_alphabet_index = (int)input_symbol_in_alphabet_index - m_shift;

      if (output_symbol_in_alphabet_index < 0)
      {
         output_symbol_in_alphabet_index = m_alphabet_len + output_symbol_in_alphabet_index;
      }
      if (output_symbol_in_alphabet_index >= m_alphabet_len)
      {
         output_symbol_in_alphabet_index = output_symbol_in_alphabet_index - m_alphabet_len;
      }

      out[symbol_index] = m_alphabet[output_symbol_in_alphabet_index];
   }
}
