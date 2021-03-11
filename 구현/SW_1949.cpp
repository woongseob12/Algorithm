#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 8
using namespace std;

int N, K, ans;
bool cut;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
void dfs(int y, int x, int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N >> K;
		int maxH = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				maxH = max(maxH, arr[i][j]);
			}
		}

		memset(visit, false, sizeof(visit));
		ans = 0;
		cut = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == maxH && !visit[i][j]) {
					visit[i][j] = true;
					dfs(i, j, 1);
					visit[i][j] = false;
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
}

void dfs(int y, int x, int cnt) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) { continue; }
		if (visit[ny][nx]) { continue; }

		if (arr[y][x] > arr[ny][nx]) {
			visit[ny][nx] = true;
			dfs(ny, nx, cnt + 1);
			visit[ny][nx] = false;
		}

		if (cut && arr[y][x] <= arr[ny][nx]) {
			cut = false;
			visit[ny][nx] = true;

			for (int d = 1; d <= K; d++) {
				if (arr[ny][nx] - d < arr[y][x]) {
					arr[ny][nx] -= d;
					dfs(ny, nx, cnt + 1);
					arr[ny][nx] += d;
				}
			}

			visit[ny][nx] = false;
			cut = true;
		}
	}
	ans = max(ans, cnt);
}
