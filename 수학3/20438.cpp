#include <iostream>
using namespace std;

bool student[5003], sleep[5003];
int attend[5003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, Q, M;
	cin >> N >> K >> Q >> M;
		
	for (int i = 0; i < K; i++) {
		int val;
		cin >> val;
		sleep[val] = true;
	}

	for (int i = 0; i < Q; i++) {
		int val;
		cin >> val;
		if (sleep[val]) continue;
		for (int j = val; j <= N + 2; j += val) {
			if (!sleep[j]) student[j] = true;
		}
	}

	for (int i = 3; i <= N + 2; i++) {
		attend[i] = attend[i - 1] + (!student[i]);
	}

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		cout << attend[E] - attend[S - 1] << "\n";
	}
}
