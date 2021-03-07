#include <iostream>
#include <algorithm>
#define MAX 50001
using namespace std;

int n, p;
int train[MAX];
int dp[4][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> train[i];
		train[i] += train[i - 1];
	}
	cin >> p;

	for (int i = 1; i <= 3; i++) {
		for (int j = i * p; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], (train[j] - train[j - p]) + dp[i - 1][j - p]);
		}
	}
	cout << dp[3][n];
}
