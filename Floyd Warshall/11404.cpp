#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m;
int map[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}

	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= n; k++) {
			if (k == j || map[j][k] == INF) {
				cout << 0 << ' ';
				continue;
			}
			else {
				cout << map[j][k] << " ";
			}
		}
		cout << '\n';
	}
}