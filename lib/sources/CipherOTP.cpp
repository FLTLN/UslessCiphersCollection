#include "CipherOTP.h"
#include <iostream>


CipherOTP::CipherOTP(char* keystream, int keystream_len){

    
    m_keystream = new char[keystream_len];

    for (int i = 0; i < keystream_len; i++)
    {
        m_keystream[i] = keystream[i];
    }

    m_keystream_len = keystream_len;

};

CipherOTP::~CipherOTP(){
    delete [] m_keystream;
};

void CipherOTP::process(char* out, char* in, int in_length){
    if(m_keystream_len<in_length){
        //exception
    }
    for (int i = 0; i < in_length; i++){
        out[i] = in[i]^m_keystream[i];
    }
};