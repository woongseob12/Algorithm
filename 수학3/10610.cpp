#include <iostream>
#include <string>
using namespace std;

int num[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string N;
	cin >> N;
	for (int i = 0; i < (int)N.size(); i++) {
		num[N[i] - '0']++;
	}
	if (num[0] == 0) {
		cout << -1 << endl;
	}
	else {
		int mul = 0;
		for (int i = 0; i <= 9; i++) {
			mul += (i * num[i]);
		}
		if (mul % 3 != 0) {
			cout << -1 << endl;
		}
		else {
			string temp;
			for (int i = 9; i >= 0; i--) {
				for (int j = 0; j < num[i]; j++) {
					temp += to_string(i);
				}
			}
			cout << temp << endl;
		}
	}
}