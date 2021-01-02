#include <iostream>
using namespace std;

int N, res, ans;
int num[101];
long long dp[101][21];
void dfs(int cnt, int sum);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> num[i];
	}
	cin >> res;

	dp[1][num[1]] = 1;
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			int plus = j + num[i];
			if (plus <= 20) { dp[i][plus] += dp[i - 1][j]; }
			int minus = j - num[i];
			if (minus >= 0) { dp[i][minus] += dp[i - 1][j]; }
		}
	}
	cout << dp[N - 1][res] << endl;
}

// 백트래킹 사용시 시간초과
void dfs(int cnt, int sum) {
	if (cnt == N - 1) {
		if (sum == res) {
			ans++;
		}
		return;
	}
	if (sum < 0 || sum > 20) {
		return;
	}
	dfs(cnt + 1, sum + num[cnt]);
	dfs(cnt + 1, sum - num[cnt]);
}
