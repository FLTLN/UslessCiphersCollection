#ifndef CIPHEROTP_H
#define CIPHEROTP_H

class CipherOTP
{
    char* m_keystream;
    int m_keystream_len;
    
    public:
        CipherOTP(char* keystream, int keystream_len);
        ~CipherOTP();
        void process(char* out, char* in, int in_length);
};

#endif
