#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MAX 101
using namespace std;

int n, m, r;
int cost[MAX];
int d[MAX];
vector<pair<int, int>> graph[MAX];
int dijk(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a].push_back({ b,l });
		graph[b].push_back({ a,l });
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dijk(i));
	}
	cout << ans;
}

int dijk(int start) {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	d[start] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ d[start], start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (cost > d[curr]) { continue; }
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			if (d[next] > d[curr] + graph[curr][i].second) {
				d[next] = d[curr] + graph[curr][i].second;
				pq.push({ d[next], next });
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] <= m) {
			sum += cost[i];
		}
	}
	return sum;
}
