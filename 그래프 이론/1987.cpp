#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R, C, ans;
char map[20][20];
bool visit[26];
pair<int, int> pos[4] = { {1,0}, {-1,0}, {0,1},{0,-1} };
void dfs(int y, int x, int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j];
		}
	}
	dfs(0, 0, 1);

	cout << ans << endl;
}

void dfs(int y, int x, int cnt) {
	if (cnt > ans) { ans = cnt; }
	visit[map[y][x] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + pos[i].first;
		int nx = x + pos[i].second;
		if (ny < 0 || ny >= R || nx < 0 || nx >= C) { continue; }
		if (!visit[map[ny][nx] - 'A']) {
			visit[map[ny][nx] - 'A'] = true;
			dfs(ny, nx, cnt + 1);
			visit[map[ny][nx] - 'A'] = false;
		}
	}
}