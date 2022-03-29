#include "CipherShift.h"
#include <iostream>
#include "Exceptions.h"

CipherShift::CipherShift(char *alphabet, int alphabet_len, int shift)
{
    m_alphabet = new char[alphabet_len];
    m_alphabet_len = alphabet_len;
    m_shift = shift;

    for (int i = 0; i < m_alphabet_len; i++)
    {
        m_alphabet[i] = alphabet[i];
    }
};

CipherShift::~CipherShift()
{
    delete[] m_alphabet;
};

void CipherShift::encrypt(char *out, char *in, int in_length)
{
    int i;
    int j;

    if (m_shift < 0)
    {

        for (i = 0; i < in_length; i++)
        {
            for (j = 0; j < m_alphabet_len; j++)
            {
                if (in[i] == m_alphabet[j])
                    break;
            }

            if(j < m_alphabet_len){

                if (j < m_shift)
                {
                    j = j + m_alphabet_len;
                }

                out[i] = m_alphabet[j - m_shift];
            }
            else{
                throw SymbolNotInAlphabet();
            }
        };
    }

    for (i = 0; i < in_length; i++)
    {

        for (j = 0; j < m_alphabet_len; j++)
        {
            if (in[i] == m_alphabet[j])
            {
                break;
            }
        }

        if(j < m_alphabet_len){

            if (j >= m_alphabet_len - m_shift)
            {
                j = j - m_alphabet_len;
            }

            out[i] = m_alphabet[j + m_shift];
        }
        else{
                throw SymbolNotInAlphabet();
        }
    };
};

void CipherShift::decrypt(char *out, char *in, int in_length)
{
    int i;
    int j;

    if (m_shift < 0){
        for (i = 0; i < in_length; i++)
        {

            for (j = 0; j < m_alphabet_len; j++)
            {
                if (in[i] == m_alphabet[j])
                {
                    break;
                }
            }

            if(j < m_alphabet_len){

                if (j >= m_alphabet_len - m_shift)
                {
                    j = j - m_alphabet_len;
                }

                out[i] = m_alphabet[j + m_shift];
            }
            else{
                throw SymbolNotInAlphabet();
            }
        };        
    };

    for (i = 0; i < in_length; i++)
    {
        for (j = 0; j < m_alphabet_len; j++)
        {
            if (in[i] == m_alphabet[j])
                break;
        }

        if(j < m_alphabet_len){

            if (j < m_shift)
            {
                j = j + m_alphabet_len;
            }

            out[i] = m_alphabet[j - m_shift];
        }
        else{
                throw SymbolNotInAlphabet();
        }
    };
};