#include <iostream>
#define MOD 1000000009
#define ll long long
using namespace std;

ll dp[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (TC--) {
		int N;
		cin >> N;
		for (int i = 4; i <= N; ++i) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
		}
		cout << dp[N] << '\n';
	}
}