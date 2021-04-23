#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> table;
void maketable(string s);
bool kmp(string s1, string s2);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string a, b, c;
	cin >> a >> b >> c;
	maketable(c);
	if (kmp(a, c) && kmp(b, c)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}

void maketable(string s) {
	int len = s.length();
	table.resize(len);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = table[j - 1];
		}
		if (s[i] == s[j]) {
			table[i] = ++j;
		}
	}
}

bool kmp(string s1, string s2) {
	int l1 = s1.length(), l2 = s2.length(), j = 0;
	for (int i = 0; i < l1; i++) {
		while (j > 0 && s1[i] != s2[j]) {
			j = table[j - 1];
		}
		if (s1[i] == s2[j]) {
			j++;
			if (j == l2) {
				return true;
			}
		}
	}
	return false;
}