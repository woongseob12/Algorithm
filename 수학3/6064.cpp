#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int ans = x;
		y %= N;
		while (ans <= M * N && ans % N != y) {
			ans += M;
		}
		if (ans > M * N) {
			cout << -1 << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}
}

