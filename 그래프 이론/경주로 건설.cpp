#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int dp[25][25];

void bfs(vector<vector<int>> board) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	dp[0][0] = 0;
	q.push({ {0,0}, {0, 0} });
	q.push({ {0,0}, {1, 0} });
	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int dir = q.front().second.first;
		int cost = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nCost = cost + 100;
			if (dir != (i / 2)) nCost += 500;
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx] == 1) continue;
			if (dp[ny][nx] == -1 || dp[ny][nx] >= nCost) {
				dp[ny][nx] = nCost;
				q.push({ {ny, nx}, {i / 2, nCost} });
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	memset(dp, -1, sizeof(dp));
	n = board.size();
	bfs(board);
	answer = dp[n - 1][n - 1];
	return answer;
}