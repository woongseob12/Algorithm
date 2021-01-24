#include <iostream>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1 << '\n';
	}
}

