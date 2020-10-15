#include <iostream>
using namespace std;

int dp[11];

int main()
{
	int TC, N;
	cin >> TC;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (TC--) {
		cin >> N;
		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[N] << endl;
	}
}