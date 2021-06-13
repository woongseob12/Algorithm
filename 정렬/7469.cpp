#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}

	sort(arr.begin(), arr.end());

	for (int loop = 0; loop < m; loop++) {
		int i, j, k;
		cin >> i >> j >> k;
		int cnt = 0;
		for (int idx = 0; idx < n; idx++) {
			if (arr[idx].second >= i && arr[idx].second <= j) {
				cnt++;
			}
			if (cnt == k) {
				cout << arr[idx].first << "\n";
				break;
			}
		}
	}
}