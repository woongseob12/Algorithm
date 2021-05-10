#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, maxV;
char arr[50][50];
int visit[50][50];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				memset(visit, 0, sizeof(visit));
				q.push({ i, j });
				visit[i][j] = 1;
				bfs();
				
			}
		}
	}
	cout << maxV;
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		maxV = max(maxV, visit[y][x] - 1);
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visit[ny][nx] == 0 && arr[ny][nx] == 'L') {
				visit[ny][nx] = visit[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}
