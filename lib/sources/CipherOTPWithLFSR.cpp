#include "CipherOTPWithLFSR.h"


CipherOTPWithLFSR::CipherOTPWithLFSR(char32_t polynomial, int polynomial_degree, char32_t seed):m_generator(polynomial, polynomial_degree, seed){
    
};

void CipherOTPWithLFSR::process(char* out, char* in, int in_length){
    for(int i = 0; i < in_length; i++){
        out[i] = in[i] ^ (char)(m_generator.generate(sizeof(char) * 8));
    }
};
