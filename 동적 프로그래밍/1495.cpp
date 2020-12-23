#include <iostream>
#include <algorithm>
using namespace std;

int N, S, M;
bool dp[101][1001];
int V[101];
void sol();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}
	sol();
}

void sol() {
	dp[0][S] = true;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {	
				if (j - V[i] >= 0) {
					dp[i][j - V[i]] = true;
				}
				if (j + V[i] <= M) {
					dp[i][j + V[i]] = true;
				}
			}
		}
	}

	for (int i = M; i >= 0; i--) {
		if (dp[N][i]) {
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
	return;
}