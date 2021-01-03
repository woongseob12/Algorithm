#include <iostream>
using namespace std;

int p1, p2, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> p1 >> p2;
	int round = 1;
	while (N != 0) {
		if ((p1 + 1) / 2 == (p2 + 1) / 2) { break; }
		p1 = (p1 + 1) / 2;
		p2 = (p2 + 1) / 2;
		round++;
		N /= 2;
	}
	if (N == 0) {
		round = -1;
	}
	cout << round << endl;
}
