#include <iostream>
#define MAX 40001
using namespace std;

int n, bead;
int c[30], b[7];
bool dp[31][MAX];
void sol(int cnt, int w);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	cin >> bead;
	for (int i = 0; i < bead; i++) {
		cin >> b[i];
	}

	sol(0, 0);

	for (int i = 0; i < bead; i++) {
		if (dp[n][b[i]]) {
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}	
}

void sol(int cnt, int w) {
	if (cnt > n) { return; }
	if (dp[cnt][w]) { return; }

	dp[cnt][w] = true;
	sol(cnt + 1, w + c[cnt]);
	sol(cnt + 1, w);
	if (w - c[cnt] > 0) {
		sol(cnt + 1, w - c[cnt]);
	}
	else {
		sol(cnt + 1, c[cnt] - w);
	}
}