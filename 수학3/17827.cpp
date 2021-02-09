#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, S;
	cin >> N >> M >> S;

	int c[200001];
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < M; i++) {
		int K;
		cin >> K;
		if (K < N) {
			cout << c[1 + K] << '\n';
		}
		else {
			int loop = K - N;
			int mod = N - S + 1;
			loop %= mod;
			cout << c[S + loop] << '\n';
		}
	}
}