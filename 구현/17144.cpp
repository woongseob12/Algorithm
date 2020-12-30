#include <iostream>
#include <queue>
using namespace std;

int R, C, T, airUp, airDown;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int map[51][51];
queue<pair<pair<int, int>, int>> q;
void spread();
void clean();
void move_m();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (airUp == 0) {
					airUp = i;
				}
				else {
					airDown = i;
				}
			}
		}
	}
	while (T--) {
		spread();
		clean();
	}

	int ans = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] != -1) {
				ans += map[i][j];
			}
		}
	}
	cout << ans << endl;
}

void spread() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] != -1 && map[i][j] != 0) {
				q.push({ { i,j }, map[i][j] });
			}
		}
	}

	while (!q.empty()) {
		int cR = q.front().first.first, cC = q.front().first.second;
		int dust = q.front().second;
		q.pop();
		if (dust / 5 == 0) { continue; }
		for (int i = 0; i < 4; i++) {
			int nR = cR + dr[i], nC = cC + dc[i];
			if (nR < 1 || nR > R || nC<1 || nC> C || map[nR][nC] == -1) { continue; }
			map[nR][nC] += dust / 5;
			map[cR][cC] -= dust / 5;
		}
	}
}

void clean() {
	int upNext, upLast = 0, downNext,downLast = 0;
	// 오른 방향
	for (int i = 2; i <= C; i++) {
		upNext = map[airUp][i];
		map[airUp][i] = upLast;
		upLast = upNext;
		// 시계
		downNext = map[airDown][i];
		map[airDown][i] = downLast;
		downLast = downNext;
	}
	// 윗 방향(반시계)
	for (int i = airUp - 1; i >= 1; i--) {
		upNext = map[i][C];
		map[i][C] = upLast;
		upLast = upNext;
	}
	// 아랫 방향(시계)
	for (int i = airDown + 1; i <= R; i++) {
		downNext = map[i][C];
		map[i][C] = downLast;
		downLast = downNext;
	}
	// 왼 방향
	for (int i = C - 1; i >= 1; i--) {
		upNext = map[1][i];
		map[1][i] = upLast;
		upLast = upNext;
		// 시계
		downNext = map[R][i];
		map[R][i] = downLast;
		downLast = downNext;
	}
	// 아랫 방향(반시계)
	for (int i = 2; i < airUp; i++) {
		upNext = map[i][1];
		map[i][1] = upLast;
		upLast = upNext;
	}
	// 윗 방향(시계)
	for (int i = R - 1; i > airDown; i--) {
		downNext = map[i][1];
		map[i][1] = downLast;
		downLast = downNext;
	}
}
