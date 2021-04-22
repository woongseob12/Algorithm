#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int T, N;
queue<pair<int, int>> q;
int arr[300][300];
bool visit[300][300];
pair<int, int> d[8] = { {-1, 0},{-1, 1},{0, 1},{1, 1},{1, 0},{1, -1},{0, -1},{-1, -1} };
int cal(int y, int x);
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int ans = 0;
		cin >> N;
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < N; j++) {
				if (s[j] == '*') {
					arr[i][j] = -1;
					visit[i][j] = true;
				}
				else {
					arr[i][j] = -2;
				}
			}
		}

		// 지뢰 개수 판별하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == -2) {
					arr[i][j] = cal(i, j);
				}
			}
		}
		
		// 주변의 지뢰가 없는 것 찾기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 0 && !visit[i][j]) {
					visit[i][j] = true;
					q.push({ i, j });
					bfs();
					ans++;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					ans++;
				}
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + d[i].first;
			int nx = x + d[i].second;
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (!visit[ny][nx]) {
				visit[ny][nx] = true;
				if (arr[ny][nx] == 0) {
					q.push({ ny, nx });
				}
			}
		}
	}
}

int cal(int y, int x) {
	int num = 0;
	for (int i = 0; i < 8; i++) {
		int ny = y + d[i].first;
		int nx = x + d[i].second;
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (arr[ny][nx] == -1) {
			num++;
		}
	}
	return num;
}