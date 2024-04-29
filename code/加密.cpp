#include <iostream>
#include <vector>

using namespace std;

vector<char> encrypt(string Ciphertext, string key) {
	
	vector<char> Plaintext(Ciphertext.size());
	int Csize = Ciphertext.size() - 1, ksize = key.size() - 1;
	
	for (int i = Csize, j = ksize; i >= 0 ; i--) {
		
		Plaintext[i] = Ciphertext[i] ^ key[j];
		if (--j == -1) {
			j = ksize;
		}
	}
	
	return Plaintext;
}

int main() {
	
	string Ciphertext, key;
	getline(cin,Ciphertext);
	getline(cin,key);
	
	vector<char> VPlaintext = encrypt(Ciphertext, key);
	
	for (int i = 0; i < VPlaintext.size(); i++) {
		cout << (int)VPlaintext[i] << " ";
	}
	
	return 0;
}
