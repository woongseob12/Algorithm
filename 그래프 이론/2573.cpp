#include <iostream>
#include <queue>
using namespace std;

int N, M, ans, ice;
int map[300][300];
bool visit[300][300];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<pair<int, int>,int>> q;
void init();
void dfs(int y, int x);
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	bool isSeperate = false;
	while (true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int nr = i + dy[k];
						int nc = j + dx[k];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M) { continue; }
						if (map[nr][nc] == 0) {
							cnt++;
						}
					}
					q.push({ {i,j},cnt });
				}
			}
		}
		bfs();
		ans++;
		ice = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					if (!visit[i][j]) {
						ice++;
						dfs(i, j);
					}
				}
			}
		}

		if (ice != 1) {
			if (ice == 0) { ans = ice; }
			cout << ans;
			break;
		}
		init();
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
		}
	}
}

void dfs(int y, int x) {
	if (visit[y][x]) {
		return;
	}
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
		if (!visit[ny][nx] && map[ny][nx] > 0) {
			dfs(ny, nx);
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		map[r][c] -= cnt;
		if (map[r][c] < 0) { map[r][c] = 0; }
	}
}

