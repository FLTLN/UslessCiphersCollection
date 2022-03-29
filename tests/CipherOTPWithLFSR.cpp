#include "tests.h"
#include "CipherOTPWithLFSR.h"
#include <iostream>
#include <bitset>

bool t_otp_with_lfsr(){
    std::cout << "Test OTP cipher with LFSR generator\n";

    char text[] = "ya ustala eto delat";
    char enc_text[19];
    char dec_text[19];

    char32_t polynomial = 0xE10000;
    char32_t seed = 0xD1020A;

    CipherOTPWithLFSR enc(polynomial, 24, seed);
    CipherOTPWithLFSR dec(polynomial, 24, seed);

    enc.process(enc_text, text, 19);
    dec.process(dec_text, enc_text, 19);


    for (size_t i = 0; i < 19; i++)
    {
        if(text[i] != dec_text[i]){
            return false; 
        }
    }

    return true;    

}
