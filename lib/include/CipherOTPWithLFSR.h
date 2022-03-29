#ifndef CIPHEROTPWITHLFSR_H
#define CIPHEROTPWITHLFSR_H

#include "GeneratorLFSR.h"

class CipherOTPWithLFSR
{
    GeneratorLFSR m_generator;
    public:
        CipherOTPWithLFSR(char32_t polynomial, int polynomial_degree, char32_t seed);
        void process(char* out, char* in, int in_length);
};

#endif
