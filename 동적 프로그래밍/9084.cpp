#include <iostream>
using namespace std;

int coin[20];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;

	while (TC--) {
		int N, money;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}
		cin >> money;

		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= money; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}

		cout << dp[money] << '\n';
		for (int i = 0; i <= money; i++) {
			dp[i] = 0;
		}
		
	}
}