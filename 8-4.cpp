#include <iostream>
#include <cstring>
using namespace std;

int main()
{	
	int testCase;
	cin >> testCase;

	int iNum;
	string s;

	for (int i = 0; i < testCase; i++) {
		cin >> iNum;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < iNum; k++) {
				cout << s[j];
			}
		}
		cout << endl;
	}
}
