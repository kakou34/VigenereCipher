#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H
#include "iostream"

std::string getKey(std::string message, std::string key);
std::string vigenereEncrypt(std::string message, std::string key);
std::string vigenereDecrypt(std::string message, std::string key);

#endif // VIGENERECIPHER_H
