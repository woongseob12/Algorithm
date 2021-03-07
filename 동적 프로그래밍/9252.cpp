#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];
string ans[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < (int)s1.size(); i++) {
		for (int j = 0; j < (int)s2.size(); j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] += dp[i][j] + 1;
				ans[i + 1][j + 1] = ans[i][j] + s1[i];
			}
			else {
				if (dp[i][j + 1] > dp[i + 1][j]) {
					dp[i + 1][j + 1] = dp[i][j + 1];
					ans[i + 1][j + 1] = ans[i][j + 1];
				}
				else {
					dp[i + 1][j + 1] = dp[i + 1][j];
					ans[i + 1][j + 1] = ans[i + 1][j];
				}
			}
		}
	}

	cout << dp[s1.size()][s2.size()] << endl;
	if (dp[s1.size()][s2.size()] != 0) {
		cout << ans[s1.size()][s2.size()];
	}
}
