#include <iostream>
#include <string>
#include <vector>
using namespace std;

int L;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> s;
	
	int len = s.size();
	int j = 0; 
	vector<int> table(len, 0);

	for (int i = 1; i < len; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = table[j - 1];
		}
		if (s[i] == s[j]) {
			table[i] = ++j;
		}
	}

	cout << len - table[len - 1];
}
