#ifndef CIPHERVIGNERE_H
#define CIPHERVIGNERE_H

class CipherVigenere
{
    char* m_alphabet; 
    int m_alphabet_len;
    char* m_key;
    int m_key_len;

    public:
        CipherVigenere(char* alphabet, int alphabet_len, char* key, int key_len);
        ~CipherVigenere();
        void encrypt(char* out, char* in, int in_length);
        void decrypt(char* out, char* in, int in_length);
};

#endif