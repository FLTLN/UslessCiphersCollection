#include "CipherVigenere.h"
#include <iostream>
#include "Exceptions.h"

CipherVigenere::CipherVigenere(char *alphabet, int alphabet_len, char *key, int key_len)
{
    m_alphabet = new char[alphabet_len];
    m_key = new char[key_len];
    m_alphabet_len = alphabet_len;
    m_key_len = key_len;

    for (int i = 0; i < m_alphabet_len; i++)
    {
        m_alphabet[i] = alphabet[i];
    }

    for (int i = 0; i < m_key_len; i++)
    {
        m_key[i] = key[i];
    }

};

CipherVigenere::~CipherVigenere()
{
    delete[] m_alphabet;
    delete[] m_key;
}

void CipherVigenere::encrypt(char *out, char *in, int in_length)
{
    int i;
    int j;
    int index_sum;
    int *index_key_elem = new int[m_key_len];
    int iterator_index_key = 0;

    for (i = 0; i < m_key_len; i++)
    {
        for (j = 0; j < m_alphabet_len; j++)
        {
            if (m_key[i] == m_alphabet[j])
            {
                break;
            }
        }

        if (j < m_alphabet_len)
        {
            index_key_elem[iterator_index_key] = j;
            iterator_index_key++;
        }

        else
        {
            throw SymbolNotInAlphabet();
        }
    }
    iterator_index_key = 0;

    for (i = 0; i < in_length; i++)
    {

        for (j = 0; j < m_alphabet_len; j++)
        {
            if (in[i] == m_alphabet[j])
            {
                break;
            }
        }

        if (j < m_alphabet_len)
        {
            index_sum = j + index_key_elem[iterator_index_key];
            iterator_index_key++;
        }

        else
        {
            throw SymbolNotInAlphabet();
        }


        if (index_sum >= m_alphabet_len)
        {
            index_sum = index_sum - m_alphabet_len;
        }

        out[i] = m_alphabet[index_sum];


        if(iterator_index_key>=m_key_len){
            iterator_index_key = 0;
        }
    }

    delete[] index_key_elem;
}

void CipherVigenere::decrypt(char *out, char *in, int in_length)
{
    int i;
    int j;
    int need_index;
    int *index_key_elem = new int[m_key_len];
    int iterator_index_key = 0;

    for (i = 0; i < m_key_len; i++)
    {
        for (j = 0; j < m_alphabet_len; j++)
        {
            if (m_key[i] == m_alphabet[j])
            {
                break;
            }
        }

        if (j < m_alphabet_len)
        {
            index_key_elem[iterator_index_key] = j;
            iterator_index_key++;
        }

        else
        {
            throw SymbolNotInAlphabet();
        }
    }
    iterator_index_key = 0;

    for (i = 0; i < in_length; i++)
    {

        for (j = 0; j < m_alphabet_len; j++)
        {
            if (in[i] == m_alphabet[j])
            {
                break;
            }
        }

        if (j < m_alphabet_len)
        {
            need_index = j - index_key_elem[iterator_index_key];
            iterator_index_key++;
        }

        else
        {
            throw SymbolNotInAlphabet();
        }


        if (need_index < 0)
        {
            need_index = need_index + m_alphabet_len;
        }

        out[i] = m_alphabet[need_index];


        if(iterator_index_key>=m_key_len){
            iterator_index_key = 0;
        }
    }

    delete[] index_key_elem;
}
