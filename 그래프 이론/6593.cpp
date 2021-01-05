#include <iostream>
#include <queue>
#include <string>
using namespace std;

int L, R, C, ans;
char map[30][30][30];
bool visit[30][30][30];
typedef struct pos {
	int l;
	int r;
	int c;
}pos;
pos start, dest;
pos dir[6] = {
	{0, 0 ,1}, {0, 0, -1},
	{0, 1, 0}, {0, -1, 0},
	{1, 0, 0}, {-1, 0, 0}
};
void input();
int bfs();
void output(int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> L >> R >> C;
	while (L != 0 && R != 0 && C != 0) {
		input();
		output(bfs());
		cin >> L >> R >> C;
	}
}

void input() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < R; j++) {
			string str;
			cin >> str;
			for (int k = 0; k < C; k++) {
				visit[i][j][k] = false;
				map[i][j][k] = str[k];
				if (map[i][j][k] == 'S') {
					start = { i,j,k };
				}
				if (map[i][j][k] == 'E') {
					dest = { i,j,k };
				}
			}
		}
	}
}

int bfs() {
	queue<pair<pos, int>> q;
	q.push({ start, 0 });
	visit[start.l][start.r][start.c] = true;
	while (!q.empty()) {
		pos temp = q.front().first;
		int cnt = q.front().second;
		if (temp.l == dest.l && temp.r == dest.r && temp.c == dest.c) { return cnt; }
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nl = temp.l + dir[i].l;
			int nr = temp.r + dir[i].r;
			int nc = temp.c + dir[i].c;
			if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) { continue; }
			if (!visit[nl][nr][nc] && map[nl][nr][nc] != '#') {
				q.push({ {nl, nr, nc},cnt + 1 });
				visit[nl][nr][nc] = true;
			}
		}
	}
	return -1;
}

void output(int ans) {
	if (ans == -1) { cout << "Trapped!\n"; }
	else { cout << "Escaped in " << ans << " minute(s).\n"; }
}