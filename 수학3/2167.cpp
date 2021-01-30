#include <iostream>
using namespace std;

int N, M, loop;
int ary[301][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int val;
			cin >> val;
			ary[i][j] = ary[i][j - 1] + val;
		}
	}

	cin >> loop;
	while (loop--) {
		int i, j, x, y, ans = 0;
		cin >> i >> j >> x >> y;
		for (int idx = i; idx <= x; idx++) {
			ans += ary[idx][y] - ary[idx][j - 1];
		}
		cout << ans << '\n';
	}
}