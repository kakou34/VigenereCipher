#include <vigenerecipher.h>
#include <iostream>
#include <string>

int main()
{
    std::string key;
    std::string message;

    std::cout << "Enter the key word: ";
    std::cin >> key;

    std::cout << "Enter the secret message: ";
    std::cin.ignore();
    std::getline(std::cin, message);  // stores all the sentence's characters in the string 'message'

    key = getKey(message, key);
    std::cout<< "The Key is : "<< key << std::endl;

    std::string encrypted = vigenereEncrypt(message, key);  // encrypt the message
    std::string decrypted = vigenereDecrypt(encrypted, key);  // decrypt the message

    std::cout<<"Original:"<<message<<std::endl;
    std::cout<<"Encrypted:"<<encrypted<<std::endl;
    std::cout<<"Decrypted:"<<decrypted<<std::endl;

    return 0;
}
