#pragma once
#include <string>

namespace Encryption{
    std::string caesarEncrypt(std::string message , int shift);
    std::string caesarDecryption(std::string encrypted_message, int shift);
}