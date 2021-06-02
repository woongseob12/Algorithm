#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, K, ans = -1;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int arr[1000][1000];
bool visit[1000][1000][11];
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	bfs();
	cout << ans;
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0, 0},{0,0} });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int cnt = q.front().first.first;
		int destroy = q.front().first.second;
		q.pop();
		if (y == N - 1 && x == M - 1) {
			ans = cnt + 1;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (destroy <= K && !visit[ny][nx][destroy]) {
				visit[ny][nx][destroy] = true;
				if (arr[ny][nx] == 0) {
					q.push({ {cnt + 1, destroy}, {ny, nx} });
				}
				else {
					q.push({ {cnt + 1, destroy + 1}, {ny, nx} });
				}
			}			
		}
	}
}