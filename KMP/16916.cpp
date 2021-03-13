#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, p;
vector<int> table;
void makeTable();
bool KMP();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> p;
	cout << KMP();

}

void makeTable() {
	int sLen = s.size();
	table.resize(sLen, 0);
	int j = 0;
	for (int i = 1; i < sLen; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = table[j - 1];
		}
		if (s[i] == s[j]) {
			table[i] = ++j;
		}
	}
}

bool KMP() {
	makeTable();
	int sLen = s.size();
	int pLen = p.size();
	int j = 0;
	for (int i = 0; i < sLen; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = table[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == pLen - 1) {
				return true;
			}
			else {
				j++;
			}
		}
	}
	return false;
}
