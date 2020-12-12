#pragma warning (disable : 4996)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, ans = 1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[1001][1001];
bool visit[1001][1001][2];
void bfs(int x, int y, int del);

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(1, 1, map[1][1]);
	if (!visit[N][M][0] && !visit[N][M][1]) {
		ans = -1;
	}
	cout << ans << endl;
}

void bfs(int x, int y, int del) {
	queue<vector<int>> q;
	q.push({ x, y, del, ans });
	visit[x][y][0] = true;
	while (!q.empty()) {
		x = q.front()[0];
		y = q.front()[1];
		del = q.front()[2];
		ans = q.front()[3];
		if (x == N && y == M) {
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i], nY = y + dy[i];
			if (nX < 1 || nX > N || nY < 1 || nY > M) { continue; }
			if (del == 1 && map[nX][nY] == 1) { continue; }
			if (visit[nX][nY][del + map[nX][nY]]) { continue; }
			q.push({ nX, nY, del + map[nX][nY], ans + 1 });
			visit[nX][nY][del + map[nX][nY]] = true;
		}
	}
}