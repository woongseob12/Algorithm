#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 1001
using namespace std;

int n, m, start, dest;
int d[MAX];
vector<pair<int, int>> graph[MAX];
vector<int> way;
int trace[MAX];
void dijk(int node);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({ e, w });
	}
	cin >> start >> dest;
	dijk(start);
}

void dijk(int node) {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}

	d[node] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ d[node], node });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (cost > d[curr]) { continue; }
		for (int i = 0; i < (int)graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			if (d[next] > d[curr] + graph[curr][i].second) {
				trace[next] = curr;
				d[next] = d[curr] + graph[curr][i].second;
				pq.push({ d[next], next });
			}
		}
	}

	cout << d[dest] << '\n';
	int temp = dest;
	while (temp != 0) {
		way.push_back(temp);
		temp = trace[temp];
	}
	cout << way.size() << '\n';
	for (int i = way.size() - 1; i >= 0; i--) {
		cout << way[i] << " ";
	}

}