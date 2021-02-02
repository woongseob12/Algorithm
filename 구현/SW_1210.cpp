#include <iostream>
using namespace std;

int t, TC = 10;
int map[100][100];
int sol(int y, int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (TC--) {
		cin >> t;
		int y = 99, x = 99;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					x = j;
				}
			}
		}
		int ans = sol(y, x);
		cout << "#" << t << " " << ans << '\n';
	}
}

int sol(int y, int x) {
	int dir = 0; // 0: 위, 1 : 왼  2: 오
	while (y != 0) {
		// 왼쪽 경로 있음
		if (x - 1 >= 0 && map[y][x - 1] == 1 && (dir == 0 || dir == 1)) {
			dir = 1;
			x--;
		}
		// 오른쪽 경로 있음
		else if (x + 1 < 100 && map[y][x + 1] == 1 && (dir == 0 || dir == 2)) {
			dir = 2;
			x++;
		}
		else {
			dir = 0;
			y--;
		}
	}
	return x;
}