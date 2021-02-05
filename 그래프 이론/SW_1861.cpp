#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;
int dfs(int y, int x);

int N, TC;
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int dp[1000][1000];
int ary[1000][1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> ary[i][j];
			}
		}
		memset(dp, 0, sizeof(dp));
		// Ç®ÀÌ
		int ansM = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ansM = max(ansM, dfs(i, j));
			}
		}
		int ansS = INF;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dp[i][j] == ansM) {
					ansS = min(ansS, ary[i][j]);
				}
			}
		}
		cout << "#" << t << " " << ansS << " " << ansM << '\n';
	}
}

int dfs(int y, int x) {
	if (dp[y][x] != 0) { return dp[y][x]; }
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if (ary[ny][nx] - ary[y][x] == 1) {
			dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
		}
	}
	return dp[y][x];
}