#include <iostream>
using namespace std;

int dp[30][30];

int main()
{
	int TC;
	cin >> TC;
	while (TC--) {
		int N, K;
		cin >> K >> N;

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				if (i == j || j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
				}
			}
		}
		cout << dp[N][K] << endl;
	}
}