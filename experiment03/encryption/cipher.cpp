#include "cipher.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

std::string Encryption::caesarEncrypt(std::string message, int shift)
{
    std::string encryptedMessage = "";
    for(auto& letter: message){
        if(letter >= 65 && letter <= 90) encryptedMessage += ((letter - 'A') + shift) % 26 + 'A' ; //checks if the letter is uppercase
        else if (letter >= 97 && letter <= 122){ //checks if the letter is lowercase
            int ascii_value = letter - 97; // subracts 97 from letter so that it would be 0 to 26
            encryptedMessage += static_cast<char>((ascii_value + shift) % 26 + 'a'); //changes the letter (e.g. 'a' changes into 'd')
        }
        else{
            encryptedMessage += letter; //just adds non-aphabetical character to the message
        }
    }   
    return encryptedMessage; //returns the message encrypted
}

std::string Encryption::caesarDecryption(std::string encrypted_message, int shift)
{
    std::string message = "";
    for(auto& letter: encrypted_message){
        if(letter >= 65 && letter <= 90) message += (((letter - 'A') - shift) + 26) % 26 + 'A' ;
        else if (letter >= 97 && letter <= 122){
            int ascii_value = letter - 97;
            message += static_cast<char>(((ascii_value - shift) + 26) % 26 + 'a');}
        else{
            message += letter;
        }
    }   
    return message;
}
