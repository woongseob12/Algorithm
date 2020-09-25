#define MAX 1001
#define MOD 10007
#include <iostream>
using namespace std;


int dp[MAX][MAX];

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < MAX; i++) {
		dp[i][1] = i;
		dp[i][i] = dp[i][0] = 1;
	}

	for (int i = 2; i < MAX; i++) {
		for (int j = 2; j < MAX; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[N][K] % MOD << endl;
}

