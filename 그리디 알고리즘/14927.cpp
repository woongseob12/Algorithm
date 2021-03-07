#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define SIZE 18
#define INF 987654321
using namespace std;

int n;
bool arr[SIZE][SIZE];
bool test[SIZE][SIZE];
int dy[] = { 1, 0 , -1, 0 };
int dx[] = { 0, 1, 0 , -1 };
void power(int y, int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = INF;
	// 첫줄이 켜져있을 수 있는 경우의 수
	for (int i = 0; i < (1 << n); i++) {
		memcpy(test, arr, sizeof(arr));
		int cnt = 0;

		// 첫줄(왼쪽에서 오른쪽으로)
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				power(0, j);
				cnt++;
			}
		}
		// 밑줄은 윗줄을 고려
		for (int j = 1; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (test[j - 1][k]) {
					power(j, k);
					cnt++;
				}
			}
		}

		// 유효한 불꺼짐인지 확인
		bool valid = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (test[i][j]) {
					valid = true;
					break;
				}
			}
		}
		if (!valid) {
			ans = min(ans, cnt);
		}
	}

	// 불을 최종적으로 끌수 있는지 확인
	if (ans == INF) {
		ans = -1;
	}
	cout << ans << "\n";
}

void power(int y, int x) {
	test[y][x] = !test[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		test[ny][nx] = !test[ny][nx];
	}
}

