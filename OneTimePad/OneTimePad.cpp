// OneTimePad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstdlib>


#include <iostream>

int main()
{
    //length of plaintext and key
    int length = 100;

    generateKey(length);

    //read plaintext
    std::string plaintext = readPlaintext("file.txt");

    //encrypt
}


