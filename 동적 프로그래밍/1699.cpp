#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main()
{
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (dp[i] == 0) {
				dp[i] = dp[i - j * j] + 1;
			}
			else {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		
	}
	cout << dp[n] << endl;
}