#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[17];

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> schedule(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> schedule[i].first >> schedule[i].second;
	}
	
	for (int i = N; i >= 1; i--) {
		if (i + schedule[i].first - 1 <= N) {
			dp[i] = max(dp[i + schedule[i].first] + schedule[i].second, dp[i + 1]);
		}
		else {
			dp[i] = dp[i + 1];
		}
	}
	cout << dp[1] << endl;
}
