#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	cin.ignore();

	while (TC--) {
		string s;
		getline(cin, s);
		int start = 0;
		for (int i = start; i < s.size(); i++) {
			if (s[i] == ' ') {
				for (int j = i - 1; j >= start; j--) {
					cout << s[j];
				}
				cout << ' ';
				start = i + 1;
			}
		}
		for (int i = s.size() - 1; i >= start; i--) {
			cout << s[i];
		}
		cout << '\n';
	}
}