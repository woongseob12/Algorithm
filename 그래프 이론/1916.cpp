#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321;
using namespace std;

int city, bus, start, dest, cost;
vector<pair<int, int>> edge[1001];	// 간선	
int d[1001];						// 최소 비용
bool visit[1001];
void sol(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> city >> bus;

	for (int i = 1; i <= city; i++) {
		d[i] = INF;;
	}

	for (int i = 1; i <= bus; i++) {
		cin >> start >> dest >> cost;
		edge[start].push_back({ dest,cost});
	}
	cin >> start >> dest;

	sol(start);
	cout << d[dest] << '\n';
}

void sol(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ d[start] , start });
	while (!pq.empty()) {
		int curr = pq.top().second;
		pq.pop();
		if (!visit[curr]) {
			visit[curr] = true;
			for (int i = 0; i < edge[curr].size(); i++) {
				int next = edge[curr][i].first;
				if (d[curr] + edge[curr][i].second < d[next]) {
					d[next] = d[curr] + edge[curr][i].second;
					pq.push({ d[next], next });
				}
			}
		}
	}
}