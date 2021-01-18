#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int N, E;
vector<pair<int, int>> graph[801];
int d[801];
bool visit[801];

void dijkstra(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[c].push_back({ a,c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	dijkstra(1);
	int w1 = d[v1];
	int w2 = d[v2];
	// 1 -> v1 -> v2 -> N;
	dijkstra(v1);
	w1 += d[v2];
	dijkstra(v2);
	w1 += d[N];
	// 1 -> v2 -> v1 -> N;
	dijkstra(v2);
	w2 += d[v1];
	dijkstra(v1);
	w2 += d[N];

	int res = min(w1, w2);
	if (res >= INF || res < 0) {
		res = -1;
	}
	cout << res << '\n';
}

void dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}

	d[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ d[start], start });
	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < (int)graph[node].size(); i++) {
			int nextNode = graph[node][i].first;
			if (d[nextNode] > d[node] + graph[node][i].second) {
				d[nextNode] = d[node] + graph[node][i].second;
				pq.push({ d[nextNode], nextNode });
			}
		}

	}
}