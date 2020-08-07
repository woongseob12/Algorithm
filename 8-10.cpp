#define ALPHABET 26
#include <iostream>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;
	int cnt = 0;
	string str;

	for (int i = 0; i < testCase; i++) {
		cin >> str;
		int alpha[ALPHABET] = { 0, };
		for (int j = 0; j < str.length(); j++) {
			if (j == 0) {
				alpha[str[j] - 97]++;
			}
			else {
				if (str[j - 1] != str[j]) {
					alpha[str[j] - 97]++;
				}
			}
		}
		bool check = false;
		for (int j = 0; j < ALPHABET; j++) {
			if (alpha[j] > 1) {
				check = true;
			}
		}
		if (check == false) {
			cnt++;
		}
	}
	cout << cnt << endl;
}
