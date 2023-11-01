// OneTimePad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

void generateKey(int length) {
	//writes key into a text file
	std::ofstream keyFile("key.txt");

	for (int i = 0; i < length; i++) {
		//ensure that the result is between 0 and 255
		char randomChar = rand() % 256;
		keyFile << randomChar;
	}

	keyFile.close();
}

//read plaintext from which to create key

//function takes one argument, reference to string called filename
//will read contents of file and return as string
std::string readPlaintext(const std::string& filename) {
	//store contents of file
	std::string plaintext;
	std::ifstream file(filename);
	//on condition that file opened successfully 
	if (file.is_open()) {
		//defines c to temporarily store each character from file
		char c;
		//while loop will continue as long as file.get(c) succeeds 
		while (file.get(c)) {
			//append each character to plaintext
			plaintext += c;
		}
		//file needs to be closed after reading
		file.close();
	}

	return plaintext;
}

//encrypt plaintext
std::string encrypt(const std::string& plaintext, const std::string& key) {
	std::string ciphertext;
	for (size_t i = 0; i < plaintext.size(); i++) {
		char encryptedChar = plaintext[i] ^ key[i];
		ciphertext += encryptedChar;
	}
	return ciphertext;
}
//decrypt 
std::string decrypt(const std::string& ciphertext, const std::string& key) {
	return encrypt(ciphertext, key);
}


void writeCiphertext(const std::string& ciphertext, const std::string& filename) {
	std::ofstream file(filename);
	if (file.is_open()) {
		file << ciphertext;
		file.close();
	}
}

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

    //decrypt
    std::string decryptedText = decrypt(ciphertext, key);

    //print
    std::cout << "decrypted: " << decryptedText << std::endl;

    return 0;
}
