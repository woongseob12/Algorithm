#include <iostream>
#include <algorithm>
#define MAX 100*1000
using namespace std;

int C, N;
pair<int, int> city[20];
int dp[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		cin >> city[i].first >> city[i].second;
	}
	
	int ans = 0;
	for (int i = 1; i <= MAX; i++) {
		for (int j = 0; j < N; j++) {
			if (i - city[j].first < 0) { continue; }
			dp[i] = max(dp[i], dp[i - city[j].first] + city[j].second);
			if (dp[i] >= C) {
				ans = i;
				break;
			}
		}
		if (ans != 0) {
			break;
		}
	}
	cout << ans;
}
