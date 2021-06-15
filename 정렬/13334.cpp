#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, d;
	cin >> n;
	vector<pair<int, int>> info(n);
	for (int i = 0; i < n; i++) {
		int h, o;
		cin >> h >> o;
		info[i].first = min(h, o);
		info[i].second = max(h, o);
	}
	cin >> d;
	sort(info.begin(), info.end(), cmp);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (info[i].second - info[i].first <= d) {
			pq.push(info[i].first);
		}
		while (!pq.empty()) {
			if (pq.top() < info[i].second - d) {
				pq.pop();
			}
			else {
				break;
			}
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
}