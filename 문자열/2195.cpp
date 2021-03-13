#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> p >> s;
	int sLen = s.length();
	int pLen = p.length();
	int loop = 0;
	for (int i = 0; i < sLen;) {
		int len = 0;
		for (int j = 0; j < pLen; j++) {
			int next = 0;
			while (j + next < pLen && p[j + next] == s[i + next]) {
				next++;
			}
			len = max(len, next);
		}
		i += len;
		loop++;
	}
	cout << loop;
}
