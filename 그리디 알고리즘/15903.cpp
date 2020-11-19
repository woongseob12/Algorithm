#define ll long long
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < n; i++) {
		ll val;
		cin >> val;
		pq.push(val);
	}

	while (m--) {
		ll temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		pq.push(temp);
		pq.push(temp);
	}

	ll ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;
}