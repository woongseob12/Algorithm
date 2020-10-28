#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int num[1001];

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}