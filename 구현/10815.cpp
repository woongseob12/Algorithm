#include <iostream>
using namespace std;

bool have[20000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, val;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val;
		have[val + 10000000] = true;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> val;
		if (have[val + 10000000]) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}
}