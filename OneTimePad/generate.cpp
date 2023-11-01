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

std::string readPlaintext(const std::string& filename) {
	std::string plaintext;
	std::ifstream file(filename);
	if (file.is_open()) {
		char c;
		while (file.get(c)) {
			plaintext += c;
		}
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

void writeCiphertext(const std::string& ciphertext, const std::string& filename) {
	std::ofstream file(filename);
	if (file.is_open()) {
		file << ciphertext;
		file.close();
	}
}