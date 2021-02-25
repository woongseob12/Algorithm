#include <iostream>
using namespace std;

bool paper[102][102];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int left, up;
		cin >> left >> up;
		for (int i = up; i < up + 10; i++) {
			for (int j = left; j < left + 10; j++) {
				paper[i][j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (paper[i][j]) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
					if (!paper[ny][nx]) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << "\n";
}
