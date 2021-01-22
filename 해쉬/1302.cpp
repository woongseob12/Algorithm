#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	map<string, int> m;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		m[s]++;
	}

	int maxNum = 0;
	string s;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (maxNum < it->second) {
			maxNum = it->second;
			s = it->first;
		}
	}
	cout << s;
}