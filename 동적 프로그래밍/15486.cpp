#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<int> dp(N + 2);
	vector<pair<int, int>> work(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> work[i].first >> work[i].second;
	}

	for (int i = 1; i <= N + 1; i++) {
		dp[i] = max(dp[i - 1], dp[i]);

		int next = i + work[i].first;
		if (next <= N + 1) {
			dp[next] = max(dp[next], dp[i] + work[i].second);
		}
	}

	cout << dp[N + 1];
}