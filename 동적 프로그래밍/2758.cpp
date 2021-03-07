#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

int n, m;
ll dp[12][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= m; i++) {
			dp[1][i] = 1;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = j * 2; k <= m; k++) {
					dp[i + 1][k] += dp[i][j];
				}
			}
		}

		ll ans = 0;
		for (int i = 1; i <= m; i++) {
			ans += dp[n][i];
		}
		cout << ans << '\n';
	}
}
