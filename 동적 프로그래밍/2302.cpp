#include <iostream>
using namespace std;

int N, M;
bool fix[41];
int dp[41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int fixSeat;
		cin >> fixSeat;
		fix[fixSeat] = true;
	}

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (fix[i] || fix[i - 1]) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	cout << dp[N] << " ";
}