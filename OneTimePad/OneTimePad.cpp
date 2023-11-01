// OneTimePad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstdlib>


#include <iostream>
//accesses previous functions 
int main()
{
    //length of plaintext and key
    int length = 100;

    generateKey(length);

    //read plaintext
    std::string plaintext = readPlaintext("plaintext.txt");

    //encrypt plaintext
    std::string key = readPlaintext("key.txt");
    std::string ciphertext = encrypt(plaintext, key);

    //write ciphertext
    writeCiphertext(ciphertext, "ciphertext.txt");
}


