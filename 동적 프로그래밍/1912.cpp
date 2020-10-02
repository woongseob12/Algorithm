#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100000];

int main()
{
	int n;
	cin >> n;
	vector<int> ary;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		ary.push_back(val);
	}

	dp[0] = ary[0];
	int ans = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + ary[i], ary[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
}