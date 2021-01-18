#include <iostream>
#include <queue>
using namespace std;

int N, island;
int map[100][100];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
bool visit[100][100];
bool checked[100][100][5001];
queue<pair<pair<int, int>, pair<int, int>>> q;
void dfs(int y, int x);
bool isSide(int y, int x);
int bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j] != 0) {
				visit[i][j] = true;
				island++;
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0 && isSide(i, j)) {
				q.push({ {i,j},{map[i][j], 0} });
			}
		}
	}
	cout << bfs();
}

void dfs(int y, int x) {
	map[y][x] = island;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
		if (!visit[ny][nx] && map[ny][nx] != 0) {
			visit[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}

bool isSide(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
		if (map[ny][nx] == 0) { return true; }
	}
	return false;
}

int bfs() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int idx = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (map[y][x] != 0 && map[y][x] != idx) {
			return cnt - 1;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (!checked[ny][nx][idx - 1] && (map[ny][nx] == 0 || map[ny][nx] != idx)) {
				checked[ny][nx][idx - 1] = true;
				q.push({ {ny,nx},{idx - 1, cnt + 1} });
			}
		}
	}
	return -1;
}