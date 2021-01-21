#include <iostream>
#define RIGHT 0
#define RIGHT_DOWN 1
#define DOWN 2
using namespace std;

int N, ans;
int map[17][17];
void dfs(int y, int x, int dir);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 2, RIGHT);
	cout << ans;
}

void dfs(int y, int x, int dir) {
	if (y == N && x == N) {
		ans++;
		return;
	}

	if (dir == RIGHT) {
		if (x + 1 <= N && map[y][x + 1] != 1) {
			dfs(y, x + 1, RIGHT);
		}
		if (x + 1 <= N && y + 1 <= N && map[y][x + 1] != 1 && map[y + 1][x] != 1 && map[y + 1][x + 1] != 1) {
			dfs(y + 1, x + 1, RIGHT_DOWN);
		}
	}
	else if (dir == RIGHT_DOWN) {
		if (x + 1 <= N && map[y][x + 1] != 1) {
			dfs(y, x + 1, RIGHT);
		}
		if (y + 1 <= N && map[y + 1][x] != 1) {
			dfs(y + 1, x, DOWN);
		}
		if (x + 1 <= N && y + 1 <= N && map[y][x + 1] != 1 && map[y + 1][x] != 1 && map[y + 1][x + 1] != 1) {
			dfs(y + 1, x + 1, RIGHT_DOWN);
		}
	}
	else {
		if (y + 1 <= N && map[y + 1][x] != 1) {
			dfs(y + 1, x, DOWN);
		}
		if (x + 1 <= N && y + 1 <= N && map[y][x + 1] != 1 && map[y + 1][x] != 1 && map[y + 1][x + 1] != 1) {
			dfs(y + 1, x + 1, RIGHT_DOWN);
		}
	}
}