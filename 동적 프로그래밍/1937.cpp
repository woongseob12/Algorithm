#include <iostream>
#include <algorithm>
using namespace std;

int N;
int map[501][501];
int dp[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dfs(int y, int x);

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dfs(i, j);
			ans = max(ans, dfs(i,j));
		}
	}
	cout << ans << endl;
}

int dfs(int y, int x)
{
	if (dp[y][x]) { return dp[y][x]; }
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i], nextX = x + dx[i];
		if ((nextY > 0 && nextY <= N) && (nextX > 0 && nextX <= N)) {
			if (map[nextY][nextX] > map[y][x]) {
				dp[y][x] = max(dp[y][x], dfs(nextY, nextX) + 1);
			}
		}
	}
	return dp[y][x];
}