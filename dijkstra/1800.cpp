#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1001
#define INF 987654321
using namespace std;

int N, P, K;
vector<pair<int,int>> graph[MAX];
vector<int> cost, way;
int d[MAX];
int trace[MAX];
bool dijk(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> P >> K;
	for (int i = 0; i < P; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({ e,w });
		graph[e].push_back({ s,w });
	}

	int ans = -1;
	int l = 0, r = 1000000, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (dijk(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans;
}

bool dijk(int val) {
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	d[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ d[1], 1 });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (cost > d[curr]) { continue; }
		for (int i = 0; i < (int)graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			if (graph[curr][i].second > val) {
				cost = 1;
			}
			else {
				cost = 0;
			}
			if (d[next] > d[curr] + cost) {
				d[next] = d[curr] + cost;
				pq.push({ d[next], next });
			}
		}
	}
	return d[N] <= K;
}

