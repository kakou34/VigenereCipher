#include "vigenerecipher.h"
#include "iostream"
#include <algorithm>


std::string getKey2(std::string message, std::string key){
   //converting key to uppercase
   transform(key.begin(), key.end(), key.begin(), ::toupper);

   // Repeating the key word in a cycle way to reach the same length as the message
    for (int i = 0; ; i++){
        if (key.size() == message.size())
            break;
        key.push_back(key[i]); // if the key length is not the same as the message, we repeat the key characters in a cycle way
    }
    int len = message.length();
    for (int i = 0; i< len ; i++){
        if (message[i] == ' ') {
            key.insert(i, " ");
        }
    }
    key = key.substr (0, len);
    return key;
}
std::string getKey(std::string message, std::string key){
   //converting key to uppercase
   transform(key.begin(), key.end(), key.begin(), ::toupper);
   int mlen = message.length();
   int klen = key.length();
   std::string newKey = "";
   // Repeating the key word in a cycle way to reach the same length as the message
   int j = 0; //index for the key
    for (int i = 0; i<mlen ; i++){
        if (message[i] == ' ') {
            newKey.push_back(' ');
        } else {
            newKey.push_back(key[j]);
            j++;
            if (j==klen){
                j=0; // go back to the start if the index is out of the interval
            }
        }
    }
    return newKey;
}

std::string vigenereEncrypt(std::string message, std::string key){
    std::string encrypted;
    int len = message.length();

    for (int i = 0; i < len; i++){
        if (message[i] >= 'a' && message[i] <= 'z' && message[i] != ' ')
            message[i] += 'A' - 'a';  // Convert to Uppercase
         else if ((message[i] < 'A' || message[i] > 'Z') && message[i] != ' ')
            continue;
        if (message[i] == ' ')
            encrypted += ' ';  // keeping the space of the message
        else
            encrypted += (message[i] + key[i]) % 26 + 'A'; // 'A' is added to bring the message in range of ASCII alphabet [A-Z]
    }
    return encrypted;
}

std::string vigenereDecrypt(std::string message, std::string key){
    std::string decrypted;
    int len = message.length();

    for (int i = 0; i < len; i++){
        if (message[i] >= 'a' && message[i] <= 'z' && message[i] != ' ')
            message[i] += 'A' - 'a';  // Convert to Uppercase
        else if ((message[i] < 'A' || message[i] > 'Z') && message[i] != ' ')
            continue;
        if (message[i] == ' ')
            decrypted += ' ';  // keeping the space of the message
        else
            decrypted += (message[i] - key[i] + 26) % 26 + 'A'; // 'A' is added to bring the message in range of ASCII alphabet [A-Z]
    }
    return decrypted;
}
