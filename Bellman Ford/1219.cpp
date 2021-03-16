#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define ll long long
#define MAX 101
#define INF 987654321
using namespace std;

int N, s, e, M;
ll dist[MAX], cost[MAX];
bool effect;
bool node[MAX], visit[MAX];
vector<pair<int, int>> graph[MAX];
bool canArrive();
bool canArrive2();
bool bellman();


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> s >> e >> M;

	for (int i = 0; i < M; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		graph[from].push_back({ to, val });
	}

	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < N; i++) {
		dist[i] = -INF;
	}

	dist[s] = cost[s];

	if (!canArrive()) {
		cout << "gg\n";
	}
	else {
		bool cycle = bellman();
		memset(visit, false, sizeof(visit));
		if (cycle && canArrive2()) {
			cout << "Gee\n";
		}
		else {
			cout << dist[e] << '\n';
		}
	}
}

bool bellman() {
	bool update = true;
	int cnt = 0;
	while (update && cnt != N + 1)
	{
		update = false;
		for (int i = 0; i < N; i++)
			for (auto j : graph[i])
			{
				if (dist[i] != -INF && dist[i] + cost[j.first] - j.second > dist[j.first])
				{
					dist[j.first] = dist[i] + cost[j.first] - j.second;
					update = true;
					if (cnt == N) {
						node[i] = true;
						node[j.first] = true;
					}
				}
			}
		cnt++;
	}
	if (cnt == N + 1) {
		return true;
	}
	return false;
}

bool canArrive() {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (curr == e) {
			return true;
		}
		for (int i = 0; i < graph[curr].size(); i++) {
			if (!visit[graph[curr][i].first]) {
				visit[graph[curr][i].first] = true;
				q.push(graph[curr][i].first);
			}
		}
	}
	return false;
}

bool canArrive2() {
	queue<int> q;
	for (int i = 0; i <= N; i++) {
		if (node[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == e) {
			return true;
		}
		visit[curr] = true;

		for (int i = 0; i < graph[curr].size(); i++) {
			if (!visit[graph[curr][i].first]) {
				q.push(graph[curr][i].first);
			}
		}
	}
	return false;
}