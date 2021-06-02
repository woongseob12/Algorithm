#define ll long long
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	ll ans = 0;
	cin >> N;

	if (N == 1) {
		cout << 0;
		return 0;
	}

	priority_queue<ll, vector<ll>, greater<>> pq;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		pq.push(val);
	}

	while (pq.size() > 2) {
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();
		ans += (a + b);
		pq.push(a + b);
	}
	
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}