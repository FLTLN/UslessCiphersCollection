#include "CipherShift.h"
#include <iostream>

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
                //exception
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
                //exception
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
                //exception
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
                //exception
        }
    };
};

// int main()
// {
//     char alphabet1[] = "world";
//     CipherShift message(alphabet1, 5, 2);
//     char out1[3];
//     char in1[] = "ldw"; //ldw orl
//     char *in2 = in1;
//     message.decrypt(out1, in1, 3);

//     for (int i = 0; i < 3; i++) {
//         cout << out1[i];
//     };
// }
