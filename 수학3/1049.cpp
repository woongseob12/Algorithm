#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int money, pack, one;
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		if (i == 0) { 
			pack = t1;
			one = t2;
			continue;
		}
		pack = min(pack, t1);
		one = min(one, t2);
	}
	money = min((N / 6 + 1) * pack, min((N/ 6) * pack + N % 6 * one ,one * N));
	cout << money << endl;
}