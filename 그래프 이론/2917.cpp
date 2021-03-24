#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MAX 500
using namespace std;

int N, M, sx, sy, ex, ey, ans;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
char arr[MAX][MAX];
int d[MAX][MAX];
queue<pair<int, int>> q;
void bfs();
void route();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == 'V') {
				sy = i;
				sx = j;
			}
			else if (arr[i][j] == '+') {
				d[i][j] = 0;
				q.push({ i,j });
			}
			else if (arr[i][j] == 'J') {
				ey = i;
				ex = j;
			}
		}
	}
	bfs();
	ans = d[sy][sx];
	route();
	cout << ans << endl;
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (d[ny][nx] == -1) {
				d[ny][nx] = d[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

void route() {
	priority_queue<pair<int, pair<int, int>>> r;
	r.push({ d[sy][sx],{ sy, sx } });
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	while (!r.empty()) {
		int cost = r.top().first;
		int y = r.top().second.first;
		int x = r.top().second.second;
		r.pop();

		ans = min(ans, cost);
		if (y == ey && x == ex) { return; }

		visit[y][x] = true;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (!visit[ny][nx]) {
				visit[ny][nx] = true;
				r.push({ d[ny][nx], { ny, nx } });
			}
		}
	}
}
