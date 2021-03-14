#include <iostream>
#include <vector>
#define MAX 501
#define INF 987654321
using namespace std;

int N, M;
long long d[MAX];
vector<pair<int, int>> graph[MAX];
bool bellman();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	if (bellman()) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (d[i] == INF) { d[i] = -1; }
			cout << d[i] << '\n';
		}
	}
}

bool bellman() {
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	d[1] = 0;

	bool update;
	for (int i = 0; i < N; i++) {
		update = false;
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int next = graph[j][k].first;
				int cost = graph[j][k].second;
				if (d[j] != INF && d[next] > d[j] + cost) {
					if (i == N - 1) { return true; }
					update = true;
					d[next] = d[j] + cost;
				}
			}
		}
		if (!update) { return false; }
	}
	return update;
}