#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 20
using namespace std;

int T, N, ans, sy, sx;
int arr[MAX][MAX];
bool num[101];
int dy[] = { -1, -1, 1, 1 };
int dx[] = { 1, -1, -1, 1 };
void sol(int y, int x, int cnt, int d);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		ans = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				memset(num, false, sizeof(num));
				sy = i;
				sx = j;
				sol(i, j, 0, 0);
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}

}

void sol(int y, int x, int cnt, int d) {
	if (y == sy + 1 && x == sx - 1) {
		ans = max(ans, cnt + 1);
		return;
	}
	int ny = y + dy[d];
	int nx = x + dx[d];
	if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
		if (!num[arr[ny][nx]]) {
			num[arr[ny][nx]] = true;
			sol(ny, nx, cnt + 1, d);
			num[arr[ny][nx]] = false;
		}
	}
	if (d >= 3) { return; }
	ny = y + dy[d + 1];
	nx = x + dx[d + 1];
	if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
		if (!num[arr[ny][nx]]) {
			num[arr[ny][nx]] = true;
			sol(ny, nx, cnt + 1, d + 1);
			num[arr[ny][nx]] = false;
		}
	}
}