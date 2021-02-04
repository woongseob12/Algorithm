#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
bool visit[100][100];
int ary[100][100];
queue<pair<int, int>> q;
bool haveCheeze();
void dfs(int y, int x);
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ary[i][j];
		}
	}

	int time = 0;
	while (haveCheeze()) {
		time++;
		// 외부 공기 체크
		dfs(0, 0);
		// 치즈 체크
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ary[i][j] == 1) {
					q.push({ i,j });
				}
			}
		}
		bfs();
		// 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ary[i][j] == -1) {
					ary[i][j] = 0;
				}
			}
		}
	}
	cout << time;
}

bool haveCheeze() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ary[i][j] == 1) {
				return true;
			}
		}
	}
	return false;
}

void dfs(int y, int x) {
	ary[y][x] = -1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
		if (!visit[ny][nx] && ary[ny][nx] == 0) {
			visit[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (ary[ny][nx] == -1) {
				cnt++;
			}
		}
		if (cnt >= 2) {
			ary[y][x] = 0;
		}
	}
}