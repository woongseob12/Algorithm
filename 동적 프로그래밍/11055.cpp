#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int ary[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ary[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = ary[i];
		for (int j = 1; j < i; j++) {
			if(ary[j] < ary[i])
			dp[i] = max(dp[i], dp[j] + ary[i]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}