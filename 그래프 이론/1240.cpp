#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, res;
bool visit[1001];
vector<pair<int,int>> graph[1001];
void dfs(int curr, int dest, int weight);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
		graph[b].push_back({ a, w });
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		res = 0;
		memset(visit, false, sizeof(visit));
		visit[a] = true;
		dfs(a, b, 0);
		cout << res << "\n";
	}
}

void dfs(int curr, int dest, int weight) {
	if (curr == dest) {
		res = weight;
		return;
	}
	for (int i = 0; i < graph[curr].size(); i++) {
		int next = graph[curr][i].first;
		int cost = graph[curr][i].second;
		if (!visit[next]) {
			visit[next] = true;
			dfs(next, dest, weight + cost);
		}
	}
}