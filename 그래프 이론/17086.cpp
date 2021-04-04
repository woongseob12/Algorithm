#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, ans;
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0 , -1, -1, -1 };
int arr[50][50];
int visit[50][50];
queue<pair<int,pair<int, int>>> q;
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ 0, { i, j } });
			}
		}
	}
	memset(visit, -1, sizeof(visit));
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visit[i][j] << " ";
			
		}
		cout << endl;
	}
	cout << ans << "\n";
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int cnt = q.front().first;
		q.pop();
		visit[y][x] = cnt;
		if (cnt > ans) {
			ans = cnt;
		}
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] != -1) continue;
			visit[ny][nx] = cnt + 1;
			q.push({ cnt + 1,{ny, nx} });
		}
	}
}
