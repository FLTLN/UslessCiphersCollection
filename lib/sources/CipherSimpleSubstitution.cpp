#include "CipherSimpleSubstitution.h"
#include <iostream>
#include "Exceptions.h"

CipherSimpleSubstitution::CipherSimpleSubstitution(char* alphabet, int alphabet_len, char* substitution_alphabet){

    m_alphabet = new char[alphabet_len];
    m_substitution_alphabet =new char [alphabet_len];
    
    m_alphabet_len = alphabet_len;

    for (int i = 0; i < m_alphabet_len; i++)
    {
        m_alphabet[i] = alphabet[i];
    }

    for (int i = 0; i < m_alphabet_len; i++)
    {
        m_substitution_alphabet[i] = substitution_alphabet[i];
    }
}

CipherSimpleSubstitution::~CipherSimpleSubstitution(){
    delete[] m_alphabet;
    delete[] m_substitution_alphabet;
}

void CipherSimpleSubstitution::encrypt(char* out, char* in, int in_length){
    int i = 0;
    int j = 0;

    for(i = 0; i < in_length; i++){
        for (j = 0; j < m_alphabet_len; j++)
        {
            if (in[i] == m_alphabet[j])
                break;
        }

        if(j < m_alphabet_len){
            out[i] = m_substitution_alphabet[j];
        }
        else{
            throw SymbolNotInAlphabet();
        }
    }

}

void CipherSimpleSubstitution::decrypt(char* out, char* in, int in_length){
    int i = 0;
    int j = 0;

    for(i = 0; i < in_length; i++){
        for (j = 0; j < m_alphabet_len; j++)
        {
            if (in[i] == m_substitution_alphabet[j])
                break;
        }

        if(j < m_alphabet_len){
            out[i] = m_alphabet[j];
        }
        else{
            throw SymbolNotInAlphabet();
        }
    }

}