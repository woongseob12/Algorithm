#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int V, E, K;
vector<pair<int,int>> edge[20001];
int d[20001];
bool visit[20001];
void sol(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({ v,w });
	}

	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}

	sol(K);
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << d[i] << '\n';
		}
	}
}

void sol(int start) {
	d[start] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ d[start], start });
	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();
		if (!visit[node]) {
			visit[node] = true;
			for (int i = 0; i < edge[node].size(); i++) {
				int nextNode = edge[node][i].first;
				if (d[nextNode] > d[node] + edge[node][i].second) {
					d[nextNode] = d[node] + edge[node][i].second;
					pq.push({ d[nextNode], nextNode });
				}
			}
		}
	}
}