#include "tests.h"
#include <iostream>
#include "CipherVigenere.h"


bool t_vigenere(){
    std::cout << "Test Vigenere Cipher generator\n";

    char alphabet[] =  "abcdefghijklmnopqrstuvwxyz";
    char key[] = "dog";

    char in[] = "program";
    char kat_out[] = "sfujfgp";
    char enc_out[7];
    char dec_out[7];

    CipherVigenere vigenere(alphabet, 26, key, 3);
    vigenere.encrypt(enc_out, in, 7);

    vigenere.decrypt(dec_out, enc_out, 7);

    for(int i = 0; i<7; i++)
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
