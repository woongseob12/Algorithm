#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int TC, N;
vector<int> price;
priority_queue<pair<int, int>> pq;
void init();
void input();
void solve();

int main() {
	init();
	solve();
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> TC;
}

void input() {
	cin >> N;
	price.clear();
	price.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> price[i];
		pq.push({ price[i], i });
	}
}

void solve() {
	while (TC--) {
		input();
		int idx = 0;
		long long ans = 0;
		while (!pq.empty()) {
			pair<int, int> curr = pq.top();
			pq.pop();
			if (curr.second < idx) continue;
			for (int i = idx; i < curr.second; i++) {
				ans += curr.first - price[i];
			}
			idx = curr.second + 1;
		}
		cout << ans << "\n";
	}
}