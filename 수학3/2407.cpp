#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string comb[101][101];
string plusString(string a, string b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) {
				comb[i][j] = to_string(1);
			}
			else {
				comb[i][j] = plusString(comb[i - 1][j - 1], comb[i - 1][j]);
			}
		}
	}
	cout << comb[n][m];
}

string plusString(string a, string b) {
	string ret;
	int sum = 0, aIdx = a.size() - 1, bIdx = b.size() - 1;
	while (aIdx >= 0 || bIdx >= 0 || sum) {
		if (aIdx >= 0) {
			sum += a[aIdx] - '0';
			aIdx--;
		}
		if (bIdx >= 0) {
			sum += b[bIdx] - '0';
			bIdx--;
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}