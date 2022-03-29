#include "CipherShift.h"
#include "tests.h"
#include <iostream>

bool t_shift()
{
    std::cout << "Test Shift Cipher generator\n";
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char in[] = "xyz";
    char kat_out[] = "abc";
    char enc_out[3];
    char dec_out[3];

    CipherShift shift(alphabet, 26, 3);
    shift.encrypt(enc_out, in, 3);

    shift.decrypt(dec_out, enc_out, 3);

    for(int i = 0; i<3; i++)
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
