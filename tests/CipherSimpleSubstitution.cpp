#include "CipherSimpleSubstitution.h"
#include "tests.h"
#include <iostream>

bool t_simple_substitution()
{
    std::cout << "Test Simple Substitution Cipher generator\n";
    char alphabet[] =               "abcdefghijklmnopqrstuvwxyz";
    char substitution_alphabet[] =  "zyxwvutsrqponmlkjihgfedcba";

    char in[] = "abcfg";
    char kat_out[] = "zyxut";
    char enc_out[5];
    char dec_out[5];

    CipherSimpleSubstitution simple_substitution(alphabet, 26, substitution_alphabet);
    simple_substitution.encrypt(enc_out, in, 5);

    simple_substitution.decrypt(dec_out, enc_out, 5);

    for(int i = 0; i<5; i++)
    {
        if(enc_out[i]!=kat_out[i]){
            return false;
        }

        if(dec_out[i]!=in[i]){
            return false;
        }
    }

    return true;
}
