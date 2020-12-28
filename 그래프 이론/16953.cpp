#include <iostream>
#include <queue>
#define MAX 1000000000
#define ll long long
using namespace std;

ll start, res;
ll bfs(ll val, int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> start >> res;
	cout << bfs(start, 1) << '\n';
}

ll bfs(ll val, int cnt) {
	queue<pair<ll, int>> q;
	q.push({ val, cnt });
	while (!q.empty()) {
		val = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (val == res) {
			return cnt;
		}

		ll temp = val * 2;
		if (temp <= res) { q.push({ temp, cnt + 1 }); }
		temp = val * 10 + 1;
		if (temp <= res) { q.push({ temp, cnt + 1 }); }
	}
	return -1;
}