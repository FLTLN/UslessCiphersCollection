# SE Project documentation

## Table of content

* [Shift (Caesar) cipher](#shift-caesar-cipher)
* [Simple substitution cipher](#simple-substitution-cipher)
* [Vigenère cipher](#vigenère-cipher)
* [OTP (One Time Pad) cipher](#otp-one-time-pad-cipher)
* [LFSR (Linear-Feedback Shift Register) pseudo random bits generator](#lfsr-linear-feedback-shift-register-pseudo-random-bits-generator)
* [OTP with keystream generated with LFSR](#otp-with-keystream-generated-with-lfsr)

## Shift (Caesar) cipher

### [Algorithm description.](https://en.wikipedia.org/wiki/Caesar_cipher)

## API Overview

```c++
class CipherShift
{
   CipherShift(char* alphabet, int alphabet_len, int shift);
   void encrypt(char* out, char* in, int in_length);
   void decrypt(char* out, char* in, int in_length);
}
```

## `CipherShift(char* alphabet, int alphabet_len, int shift)`

### Description

Class constructor. Performs cipher initialization.

### Arguments

`alphabet` - Input. Alphabet for what encryption will be performed. Array of `char` with assumed length at least `alphabet_len` elements.

`alphabet_len` - Input. Length of alphabet for what encryption will be performed.

`shift` - Input. Encryption/decryption key. Can be both positive and negative.

### Exceptions

This method does not throw any exceptions.

## `void encrypt(char* out, char* in, int in_length)`

### Description

Performs encryption.

### Arguments

`out` - Output. Buffer to store encryption result. Array of `char` with assumed length at least `in_length` elements.

`in` - Input. Buffer with message to be encrypted. Array of `char` with assumed length at least `in_length` elements.

`in_length` - Input. Length of buffer with message to be encrypted.

### Exceptions

This method throw `SymbolNotInAlphabet` exception if symbol from `in` does not found in alphabet.

## `void decrypt(char* out, char* in, int in_length)`

### Description

Performs encryption.

### Arguments

`out` - Output. Buffer to store decryption result. Array of `char` with assumed length at least `in_length` elements.

`in` - Input. Buffer with message to be decrypted. Array of `char` with assumed length at least `in_length` elements.

`in_length` - Input. Length of buffer with message to be decrypted.

### Exceptions

This method throw `SymbolNotInAlphabet` exception if symbol from `in` does not found in alphabet.

## Simple substitution cipher

### [Algorithm description.](<https://en.wikipedia.org/wiki/Substitution_cipher>)

## API Overview

```c++
class CipherSimpleSubstitution
{
   CipherSimpleSubstitution(char* alphabet, int alphabet_len, char* substitution_alphabet);
   void encrypt(char* out, char* in, int in_length);
   void decrypt(char* out, char* in, int in_length);
}
```

## `CipherSimpleSubstitution(char* alphabet, int alphabet_len, char* substitution_alphabet)`

### Description

Class constructor. Performs cipher initialization.

### Arguments

`alphabet` - Input. Alphabet for what encryption will be performed. Array of `char` with assumed length at least `alphabet_len` elements.

`alphabet_len` - Input. Length of alphabet for what encryption will be performed.

`substitution_alphabet` - Input. Alphabet for what encryption will be performed. Array of `char` with assumed length at least `alphabet_len` elements.

### Exceptions

This method does not throw any exceptions.

## `void encrypt(char* out, char* in, int in_length)`

### Description

Performs encryption.

### Arguments

`out` - Output. Buffer to store encryption result. Array of `char` with assumed length at least `in_length` elements.

`in` - Input. Buffer with message to be encrypted. Array of `char` with assumed length at least `in_length` elements.

`in_length` - Input. Length of buffer with message to be encrypted.

### Exceptions

This method throw `SymbolNotInAlphabet` exception if symbol from `in` does not found in alphabet.

## `void decrypt(char* out, char* in, int in_length)`

### Description

Performs encryption.

### Arguments

`out` - Output. Buffer to store decryption result. Array of `char` with assumed length at least `in_length` elements.

`in` - Input. Buffer with message to be decrypted. Array of `char` with assumed length at least `in_length` elements.

`in_length` - Input. Length of buffer with message to be decrypted.

### Exceptions

This method throw `SymbolNotInAlphabet` exception if symbol from `in` does not found in alphabet.

## Vigenère cipher

### [Algorithm description.](https://en.wikipedia.org/wiki/Vigenère_cipher)

## API Overview

```c++
class CipherVigenere
{
   CipherVigenere(char* alphabet, int alphabet_len, char* key, int key_len)
   void encrypt(char* out, char* in, int in_length);
   void decrypt(char* out, char* in, int in_length);
}
```

## `CipherVigenere(char* alphabet, int alphabet_len, char* key, int key_len)`

### Description

Class constructor. Performs cipher initialization.

### Arguments

`alphabet` - Input. Alphabet for what encryption will be performed. Array of `char` with assumed length at least `alphabet_len` elements.

`alphabet_len` - Input. Length of alphabet for what encryption will be performed.

`key` - Input. Key to perform encryption/decryption. Array of `char` with assumed length at least `key_len` elements.

`key_len` - Input. Length of key with what encryption/decryption will be performed.

### Exceptions

This method does not throw any exceptions.

## `void encrypt(char* out, char* in, int in_length)`

### Description

Performs encryption.

### Arguments

`out` - Output. Buffer to store encryption result. Array of `char` with assumed length at least `in_length` elements.

`in` - Input. Buffer with message to be encrypted. Array of `char` with assumed length at least `in_length` elements.

`in_length` - Input. Length of buffer with message to be encrypted.

### Exceptions

This method throw `SymbolNotInAlphabet` exception if symbol from `in` does not found in alphabet.

## `void decrypt(char* out, char* in, int in_length)`

### Description

Performs encryption.

### Arguments

`out` - Output. Buffer to store decryption result. Array of `char` with assumed length at least `in_length` elements.

`in` - Input. Buffer with message to be decrypted. Array of `char` with assumed length at least `in_length` elements.

`in_length` - Input. Length of buffer with message to be decrypted.

### Exceptions

This method throw `SymbolNotInAlphabet` exception if symbol from `in` does not found in alphabet.

## OTP (One Time Pad) cipher

### [Algorithm description.](https://en.wikipedia.org/wiki/One-time_pad)

## API Overview

```c++
class CipherOTP
{
   CipherOTP(char* keystream, int keystream_len);
   void process(char* out, char* in, int in_length);
}
```

## `CipherOTP(char* keystream, int keystream_len)`

### Description

Class constructor. Performs cipher initialization.

### Arguments

`keystream` - Input. Keystream for encryption/decryption. Array of `char` with assumed length at least `keystream_len` elements.

`keystream_len` - Input. Length of keystream for encryption/decryption.

### Exceptions

This method does not throw any exceptions.

## `void process(char* out, char* in, int in_length)`

### Description

Performs encryption/decryption.

### Arguments

`out` - Output. Buffer to store encryption/decryption result. Array of `char` with assumed length at least `in_length` elements.

`in` - Input. Buffer with message to be encrypted/decrypted. Array of `char` with assumed length at least `in_length` elements.

`in_length` - Input. Length of buffer with message to be encrypted/decrypted.

### Exceptions

This method throw `InsufficientKeystream` exception if the length of keystream is less than the length of message.

>NOTE: OTP must be re-initialized with the same keystream to perform decryption of previously encrypted message and vice-versa.

## LFSR (Linear-Feedback Shift Register) pseudo random bits generator

### [Algorithm description.](https://en.wikipedia.org/wiki/Linear-feedback_shift_register)

## API Overview

```c++
class GeneratorLFSR
{
   GeneratorLFSR(char32_t polynomial, int polynomial_degree, char32_t seed);
   char32_t generate(int number_of_bits);
}
```

## `GeneratorLFSR(char32_t polynomial, int polynomial_degree, char32_t seed)`

### Description

Class constructor. Performs generator initialization.

### Arguments

`polynomial` - Input. Polynomial to choose feedback bits. Only `polynomial_degree - 1` low bits will be taken into account during initialization.

`polynomial_degree` - Input. Degree of polynomial to choose feedback bits.

`seed` - Input. Initial state of generator.

> NOTE: Pay attention to polynomial. Number of bits generated without repetitions is highly depends by chosen polynomial. With some polynomials number of bits generated without repetitions is  depends on seed.

### Exceptions

This method throw `IllegalPolynomialDegree` exceptions if `polynomial_degree - 1` is greater than `char32_t` size in bits.

## `char32_t generate(int number_of_bits)`

### Description

Generates sequence of up to 32 pseudo random bits.

### Arguments

`number_of_bits` - Input. Number of bits to generate.

Returns sequence with `number_of_bits` pseudo random bits.

### Exceptions

This method throw `IllegalNumberOfBits` exceptions if `number_of_bits` is greater than `char32_t` size in bits.

## OTP with keystream generated with LFSR

## Algorithm description

This algorithm performs OTP encryption/decryption with keystream generated by LFSR.

## API Overview

```c++
class CipherOTPWithLFSR
{
   CipherOTPWithLFSR(char32_t polynomial, int polynomial_degree, char32_t seed);
   void process(char* out, char* in, int in_length);
}
```

## `CipherOTPWithLFSR(char32_t polynomial, int polynomial_degree, char32_t seed)`

### Description

Class constructor. Performs generator initialization.

### Arguments

`polynomial` - Input. Polynomial to choose feedback bits. Only `polynomial_degree - 1` low bits will be taken into account during initialization.

`polynomial_degree` - Input. Degree of polynomial to choose feedback bits.

`seed` - Input. Initial state of generator.

> NOTE: Pay attention to polynomial. Number of bits generated without repetitions is highly depends by chosen polynomial. With some polynomials number of bits generated without repetitions is  depends on seed.

### Exceptions

This method throw `IllegalPolynomialDegree` exceptions if `polynomial_degree - 1` is greater than `char32_t` size in bits.

## `void process(char* out, char* in, int in_length)`

### Description

Performs encryption/decryption.

### Arguments

`out` - Output. Buffer to store encryption/decryption result. Array of `char` with assumed length at least `in_length` elements.

`in` - Input. Buffer with message to be encrypted/decrypted. Array of `char` with assumed length at least `in_length` elements.

`in_length` - Input. Length of buffer with message to be encrypted/decrypted.

### Exceptions

This method does not throw any exceptions.

>NOTE: OTP with LFSR must be re-initialized with the same keystream to perform decryption of previously encrypted message and vice-versa.
