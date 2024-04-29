#include <iostream>
#include <vector>

using namespace std;

vector<char> Decrypt(vector<int> Plaintext, string key) {
	
	int Psize = Plaintext.size() - 1, ksize = key.size() - 1;
	vector<char> Ciphertext(Plaintext.size());
	
	for (int i = Psize, j = ksize; i >= 0 ; i--) {
		
		Ciphertext[i] = Plaintext[i] ^ key[j];
		
		if (--j == -1) {
			j = ksize;
		}
	}
	
	return Ciphertext;
}

int main() {
	
	string SPlaintext, key;
	vector<int> VPlaintext;
	getline(cin,SPlaintext);
	getline(cin,key);
	
	int Number = 0;
	for (int i = 0; i < SPlaintext.size(); i++) {
		if (SPlaintext[i] >= '0' && SPlaintext[i] <= '9') {
			Number = Number * 10 + (SPlaintext[i] - '0');
		} else {
			VPlaintext.push_back(Number);
			Number = 0;
		}
	}
	VPlaintext.push_back(Number);

	vector<char> Plaintext = Decrypt(VPlaintext,key);
	
	for(int i = 0; i < Plaintext.size(); i++) {
		cout << Plaintext[i];
	}
	
	return 0;
}
