#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> coin(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin.begin(), coin.end());

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = coin[0]; j <= k; j++ ) {
			dp[j] += dp[j - coin[i]];
		}
	}
	
	cout << dp[k] << endl;

}