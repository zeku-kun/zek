#include "cipher.hpp"
#include <iostream>
#include <string>

int main(){
    std::cout << Encryption::caesarEncrypt("Zech Danzig Lucian C. Este", 3) << std::endl;
    std::cout << Encryption::caesarDecryption("Chfk Gdqclj Oxfldq F. Hvwh" , 3);
    return 0;
}