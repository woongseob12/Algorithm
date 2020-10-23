#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];
int matrix[501][2];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> matrix[i][0] >> matrix[i][1];
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 0;
	}

	for (int diagonal = 1; diagonal <= N - 1; diagonal++) {
		for (int i = 1; i <= N - diagonal; i++) {
			int j = i + diagonal;
			for (int k = i; k <= j - 1; k++) {
				if (dp[i][j] == 0) {
					dp[i][j] = dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1];
				}
				else {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1]);
				}
			}
		}
	}
	cout << dp[1][N] << endl;
}