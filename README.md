# SE Project

## Description

This small repository is a cryptography related group pet project. Implemented ciphers does not provide any kind of security, but can be used for study how its works. The main purpose if this repository is to pass university exam.

## Functionality that should be implemented

The following functionality is implemented in this repository:

* [Shift (Caesar) cipher](https://en.wikipedia.org/wiki/Caesar_cipher)

* [Simple substitution cipher](https://en.wikipedia.org/wiki/Substitution_cipher)

* [Vigenère cipher](https://en.wikipedia.org/wiki/Vigenère_cipher)

* [OTP (One Time Pad) cipher](https://en.wikipedia.org/wiki/One-time_pad)

* [LFSR (Linear-Feedback Shift Register) pseudo random bits generator](https://en.wikipedia.org/wiki/Linear-feedback_shift_register)

* OTP with keystream generated with LFSR

## Used language, tools and environment

* C++, standard does not matter

* Windows Subsystem for Linux with Ubunty 18.04 lts

* gcc version 9.3.0 or later

* cmake version 3.16.2 or later

* GNU make version 4.2 or later

## API

See [documentation](./DOCUMENTATION.md) for further details.

```c++
// Shift (Caesar) cipher
class CipherShift
{
   CipherShift(char* alphabet, int alphabet_len, int shift);
   void encrypt(char* out, char* in, int in_length);
   void decrypt(char* out, char* in, int in_length);
}

// Simple substitution cipher
class CipherSimpleSubstitution
{
   CipherSimpleSubstitution(char* alphabet, int alphabet_len, char* substitution_alphabet);
   void encrypt(char* out, char* in, int in_length);
   void decrypt(char* out, char* in, int in_length);
}

// Vigenère cipher
class CipherVigenere
{
   CipherVigenere(char* alphabet, int alphabet_len, char* key, int key_len);
   void encrypt(char* out, char* in, int in_length);
   void decrypt(char* out, char* in, int in_length);
}

// OTP (One Time Pad) cipher
class CipherOTP
{
   CipherOTP(char* keystream, int keystream_len);
   void process(char* out, char* in, int in_length);
}

// LFSR (Linear-Feedback Shift Register) pseudo random bits generator
class GeneratorLFSR
{
   GeneratorLFSR(char32_t polynomial, int polynomial_degree, char32_t seed);
   char32_t generate(int number_of_bits);
}

// OTP with keystream generated with LFSR
class CipherOTPWithLFSR
{
   CipherOTPWithLFSR(char32_t polynomial, int polynomial_degree, char32_t seed);
   void process(char* out, char* in, int in_length);
}

```

## Quality requirements

* All implemented ciphers and generators should throw appropriate exceptions:

```c++
// Encryption and decryption with CipherShift, CipherSimpleSubstitution and CipherVigenere
struct SymbolNotInAlphabet : public std::exception
{
   const char * what () const throw ()
   {
      return "Symbol in input string does not found in alphabet";
   }
}

// Encryption and decryption with One Time Pad
struct InsufficientKeystream : public std::exception
{
   const char * what () const throw ()
   {
      return "Keystream length is less than input string length";
   }
}

// LFSR and OTP with LFSR
struct IllegalPolynomialDegree : public std::exception
{
   const char * what () const throw ()
   {
      return "Given polynomial degree is illegal";
   }
}

struct IllegalNumberOfBits : public std::exception
{
   const char * what () const throw ()
   {
      return "Requested number of bits is illegal";
   }
}

```

* All implemented functionality should be covered by functional testing
* All implemented tests should runs on pool request using GitHub Actions
* All implemented functionality should be documented

## Branch naming and commit message conventions

The following rule should be applied to branch names - `dev/<user_tag>/<branch_name>`

The following rules should be applied to commit messages - `[<change_type>][<change_status>] <commit description>`, where:

|Change type tag|Tag meaning|
|---|---|
|DOC|Documentation|
|TEST|Testing|
|FUNC|Functionality|

|Change status tag|Tag meaning|
|---|---|
|NEW|Adding completely new functional, test or documentation|
|CHANGE|Change existing functional, test or documentation to improve it|
|FIX|Change existing functional, test or documentation to fix it|
