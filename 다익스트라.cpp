#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
#define MAX 20001

using namespace std;

vector<pair<int, int>> a[MAX];	
int d[MAX] = {INF, };	// 시작점에서 모든 노드로의 최단 경로를 저장하는 배열

void dijkstra(int start) {
	
	priority_queue<pair<int, int>> pq;	
	d[start] = 0;

	pq.push(make_pair(0, start));

	while(!pq.empty()) {
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (d[current] < distance) { continue; }

		for (int i = 0; i < (int)a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = a[current][i].second;

			if (d[current] + nextDistance < d[next]) {
				d[next] = d[current] + nextDistance;
				pq.push(make_pair(-d[next], next));
			}
		}
	}
}

int main()
{
	int V, E;
	cin >> V >> E;
	int start;
	cin >> start;
	vector<pair<int, int>> a[MAX];
	for (int i = 0; i < E; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		a[from].push_back(make_pair(to, weight));
	}

	vector<int> d(V + 1, INF);
	priority_queue<pair<int, int>> pq;
	d[start] = 0;

	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (d[current] < distance) { continue; }

		for (int i = 0; i < (int)a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = a[current][i].second;

			if (d[current] + nextDistance < d[next]) {
				d[next] = d[current] + nextDistance;
				pq.push(make_pair(-d[next], next));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) { cout << "INF" << endl; }
		else {
			cout << d[i] << endl;
		}
	}
}
