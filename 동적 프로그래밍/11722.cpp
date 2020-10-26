#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int ary[1001];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ary[i];
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (ary[j] > ary[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}