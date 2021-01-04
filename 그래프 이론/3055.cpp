#include <iostream>
#include <queue>
#include <string>
using namespace std;

int R, C, ans;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
char map[50][50];
bool W[50][50];
bool P[50][50];
pair<int, int> hedgehog, dest;
queue<pair<pair<int, int>, int>> water;
queue<pair<pair<int, int>, int>> pos;
int bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < (int)str.size(); j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'S') {
				hedgehog.first = i;
				hedgehog.second = j;
				pos.push({ { i,j }, 0 });
			}
			else if (map[i][j] == 'D') {
				dest.first = i;
				dest.second = j;
			}
			else if (map[i][j] == '*') {
				water.push({ { i,j }, 0 });
			}
		}
	}

	ans = bfs();
	if (ans == -1) { cout << "KAKTUS\n"; }
	else { cout << ans << '\n'; }
}

int bfs() {
	int count = 1;
	while (1) {
		while (!water.empty()) {
			int r = water.front().first.first;
			int c = water.front().first.second;
			int cnt = water.front().second;
			if (cnt == count) { break; }
			water.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nr >= R || nc < 0 || nc >= C) { continue; }
				if (!W[nr][nc] && map[nr][nc] == '.') {
					W[nr][nc] = true;
					map[nr][nc] = '*';
					water.push({ { nr,nc },cnt + 1 });
				}
			}
		}
		while (!pos.empty()) {
			int y = pos.front().first.first;
			int x = pos.front().first.second;
			int dist = pos.front().second;
			if (y == dest.first && x == dest.second) {
				return dist;
			}
			if (dist == count) { break; }
			pos.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dr[i];
				int nx = x + dc[i];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C) { continue; }
				if (!P[ny][nx] && (map[ny][nx] == '.' || map[ny][nx] == 'D')) {
					P[ny][nx] = true;
					pos.push({ { ny,nx },dist + 1 });
				}
			}
		}
		count++;
		if (pos.empty()) {
			break;
		}
	}
	return -1;
}