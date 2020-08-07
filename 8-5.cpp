#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int alphabet[26] = { 0, };
	string word;
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] >= 97 && word[i] <= 122) {
			word[i] -= 32;
		}
	}
	for (int i = 0; i < word.length(); i++) {
		alphabet[word[i] - 65]++;
	}
	int max = 0;
	int sequence = 0;
	for (int i = 0; i < 26; i++) {
		if (max < alphabet[i]) {
			max = alphabet[i];
			sequence = i;
		}
	}
	int sameExist = 0;
	for (int i =0; i< 26; i ++){
		if (max == alphabet[i]) {
			sameExist++;
		}
	}
	if (sameExist != 1) {
		cout << '?';
	}
	else {
		cout << (char)(sequence + 65);
	}
}
