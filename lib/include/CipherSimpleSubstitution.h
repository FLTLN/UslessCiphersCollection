#ifndef CIPHERSIMPLESUBSTITUTION_H
#define CIPHERSIMPLESUBSTITUTION_H

class CipherSimpleSubstitution
{
    char* m_alphabet; 
    int m_alphabet_len;
    char* m_substitution_alphabet;

    public:
        CipherSimpleSubstitution(char* alphabet, int alphabet_len, char* substitution_alphabet);
        ~CipherSimpleSubstitution();
        void encrypt(char* out, char* in, int in_length);
        void decrypt(char* out, char* in, int in_length);
};

#endif
