#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	vector<pair<int, int>> pos(N);
	for (int i = 0; i < N; i++) {
		cin >> pos[i].first >> pos[i].second;
	}
	sort(pos.begin(), pos.end());

	vector<int> arr, dp(N);
	vector<bool> check(N);
	int idx = 0;
	arr.push_back(pos[0].second);
	for (int i = 1; i < N; i++) {
		if (arr[arr.size() - 1] < pos[i].second) {
			arr.push_back(pos[i].second);
			dp[i] = ++idx;
		}
		else {
			int s = lower_bound(arr.begin(), arr.end(), pos[i].second) - arr.begin();
			arr[s] = pos[i].second;
			dp[i] = s;
		}
	}
	cout << N - arr.size() << "\n";
	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == idx) {
			check[i] = true;
			idx--;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			cout << pos[i].first << "\n";
		}
	}
}