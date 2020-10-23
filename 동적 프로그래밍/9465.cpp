#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001][2];

int main()
{
	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		cin >> n;
		vector<int[2]> sticker(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> sticker[i][0];
		}
		for (int i = 1; i <= n; i++) {
			cin >> sticker[i][1];
		}
		dp[1][0] = sticker[1][0];
		dp[1][1] = sticker[1][1];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][1] + sticker[i][0], dp[i - 2][1] + sticker[i][0]);
			dp[i][1] = max(dp[i - 1][0] + sticker[i][1], dp[i - 2][0] + sticker[i][1]);

		}
		cout << max(dp[n][0], dp[n][1]) << endl;
	}
}