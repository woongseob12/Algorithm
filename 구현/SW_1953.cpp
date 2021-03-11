#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, r, c, l;
int arr[50][50];
int visit[50][50];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
void bfs(int r, int c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> r >> c >> l;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) { arr[i][j] = 15; }
				else if (arr[i][j] == 2) { arr[i][j] = 10; }
				else if (arr[i][j] == 3) { arr[i][j] = 5; }
				else if (arr[i][j] == 4) { arr[i][j] = 9; }
				else if (arr[i][j] == 5) { arr[i][j] = 3; }
				else if (arr[i][j] == 6) { arr[i][j] = 6; }
				else if (arr[i][j] == 7) { arr[i][j] = 12; }
			}
		}

		memset(visit, false, sizeof(visit));
		bfs(r, c);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j]) { ans++; }
			}
		}
		
		cout << "#" << t << " " << ans << '\n';
	}
}

void bfs(int r, int c) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r, c}, 1 });
	while (!q.empty()) {
		r = q.front().first.first;
		c = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		visit[r][c] = true;
		for (int i = 0; i < 4; i++) {
			if (arr[r][c] & (1 << i)) {
				int nr = r + dy[i];
				int nc = c + dx[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m) { continue; }
				if (!visit[nr][nc] && cnt + 1 <= l && arr[nr][nc] != 0) {
					if (arr[nr][nc] & (1 << ((i + 2) % 4))) {
						q.push({ {nr,nc}, cnt + 1 });
					}
				}
			}
		}
	}
}
