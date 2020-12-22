#include <iostream>
using namespace std;

int N, M, K, y, x;
int map[15][15];
int dp[15][15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;

	if (K == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		cout << dp[N - 1][M - 1] << '\n';
	}

	else {
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = cnt;
				cnt++;
			}
		}

		int stop, y, x;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				if (map[i][j] == K) {
					stop = dp[i][j];
					y = i, x = j;
					break;
				}
			}
		}

		for (int i = y; i < N; i++) {
			for (int j = x; j < M; j++) {
				if (i == y || j == x) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		stop *= dp[N - 1][M - 1];
		cout << stop << '\n';
	}
}
