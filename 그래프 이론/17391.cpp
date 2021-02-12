#include <iostream>
#include <queue>
using namespace std;

int N, M;
int ary[300][300];
bool visit[300][300];
int bfs();

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

	cout << bfs();
}

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 0 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (y == N - 1 && x == M - 1) {
			return cnt;
		}
		for (int i = ary[y][x]; i > 0; i--) {
			int ny = y + i;
			int nx = x;
			if (ny < N && nx < M && !visit[ny][nx]) {
				visit[ny][nx] = true;
				q.push({ {ny,nx}, cnt + 1 });
			}
			ny = y;
			nx = x + i;
			if (ny < N && nx < M && !visit[ny][nx]) {
				visit[ny][nx] = true;
				q.push({ {ny,nx}, cnt + 1 });
			}
		}
	}
	return 0;
}
