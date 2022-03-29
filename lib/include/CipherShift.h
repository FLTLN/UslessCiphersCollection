#ifndef CIPHERSHIFT_H
#define CIPHERSHIFT_H

class CipherShift
{
    char *m_alphabet;
    int m_alphabet_len;
    int m_shift;

    public:
        CipherShift(char *alphabet, int alphabet_len, int shift);
        ~CipherShift();
        void encrypt(char *out, char *in, int in_length);
        void decrypt(char *out, char *in, int in_length);
};

#endif