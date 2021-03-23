#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> table;

	while (true) {
		string s;
		cin >> s;
		if (s == ".") {
			break;
		}
		int len = s.size();
		table.clear();
		table.resize(len, 0);
		int j = 0;
		for (int i = 1; i < len; i++) {
			while (j > 0 && s[i] != s[j]) {
				j = table[j - 1];
			}
			if (s[i] == s[j]) {
				table[i] = ++j;
			}
		}
		if (len % (len - table[len - 1]) == 0) {
			cout << len / (len - table[len - 1]) << "\n";
		}
		else {
			cout << "1\n";
		}
	}
}