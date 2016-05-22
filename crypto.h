#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>

class Crypto
{
public:
    Crypto();
    bool encrypt(std::string fname, std::string key);
    bool decrypt(std::string fname, std::string key);
};

#endif // CRYPTO_H
