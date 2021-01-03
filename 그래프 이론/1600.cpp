#include <iostream>
#include <queue>
using namespace std;

typedef struct monkey {
	int y;
	int x;
	int jump;
	int cnt;
}monkey;
int K, W, H, ans;
int map[201][201];
pair<int, int> pos[12] = {
	{1,0}, {0,1}, {-1,0}, {0,-1},
	{2,1}, {1,2}, {-1,2}, {-2,1},
	{-2,-1}, {-1,-2}, {1,-2}, {2,-1}
};
bool visit[201][201][31];
int bfs(int y, int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> W >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> map[i][j];
		}
	}
	ans = bfs(1, 1);
	cout << ans << '\n';
}

int bfs(int y, int x) {
	queue<monkey> q;
	monkey temp = { y,x,map[y][x], 0 };
	q.push(temp);
	while (!q.empty()) {
		monkey info = q.front();
		q.pop();
		if (info.y == H && info.x == W) {
			return info.cnt;
		}
		for (int i = 0; i < 12; i++) {
			int ny = info.y + pos[i].first;
			int nx = info.x + pos[i].second;
			if (ny < 1 || ny > H || nx < 1 || nx > W) { continue; }
			int nj = info.jump;
			if (i > 3) { nj += 1; }
			if (!visit[ny][nx][nj] && nj <= K && map[ny][nx] != 1) {
				monkey next = { ny, nx, nj, info.cnt + 1 };
				q.push(next);
				visit[ny][nx][nj] = true;
			}
		}
	}
	return -1;
}