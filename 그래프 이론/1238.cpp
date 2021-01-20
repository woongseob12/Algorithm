#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, X;
vector<pair<int, int>> graph[1001];
int dist[1001];
void dijk(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		graph[s].push_back({ e, t });
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		dijk(i);
		temp += dist[X];
		dijk(X);
		temp += dist[i];
		ans = max(ans, temp);
	}
	cout << ans;
}

void dijk(int start) {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ dist[start], start });
	while(!pq.empty()) {
		int curr = pq.top().second;
		pq.pop();
		for (int i = 0; i < (int)graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			if (dist[next] > dist[curr] + graph[curr][i].second) {
				dist[next] = dist[curr] + graph[curr][i].second;
				pq.push({ dist[next], next });
			}
		}
	}
}