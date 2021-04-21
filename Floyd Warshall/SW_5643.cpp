#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M;
int map[501][501];
int way[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = INF;
			}
		}

		for (int i = 1; i <= N; i++) {
			way[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) { continue; }
				if (map[i][j] != INF) {
					way[i]++;
					way[j]++;
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			if (way[i] == N - 1) {
				ans++;
			}
		}
		cout << "#" << t << " " << ans << '\n';
	}
}