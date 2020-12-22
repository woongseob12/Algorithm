#define MOD 1000000
#include <iostream>
#include <string>
using namespace std;

int dp[5000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string pw;
	cin >> pw;

	dp[0] = 1;

	for (int i = 1; i <= (int)pw.size(); i++) {
		if (pw[i - 1] != '0') {
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}
		if (i == 1) { continue; }
		if (pw[i - 2] == '1' || (pw[i - 2] == '2' && pw[i - 1] <= '6')) {
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}

	cout << dp[pw.size()] << '\n';
}
