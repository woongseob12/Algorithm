#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dp[501][501];
int map[501][501];
int dfs(int y, int x);

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(N, M) << endl;

}

int dfs(int y, int x)
{
	if (dp[y][x] != -1) { return dp[y][x]; }
	if (y == 1 && x == 1) { return 1;  }
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i], nextX = x + dx[i];
		if ((nextY >= 1 && nextY <= N) && (nextX >= 1 && nextX <= M)) {
			if (map[nextY][nextX] > map[y][x]) {
				dp[y][x] += dfs(nextY, nextX);
			}
		}
	}
	return dp[y][x];
}