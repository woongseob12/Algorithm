#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[50001];

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = 4;
		for (int j = sqrt(i); j > 0; j--) {
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}

	cout << dp[N] << endl;
}