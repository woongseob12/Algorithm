#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int N, M, W, S, E, T;
vector<pair<int, int>> edge[501];
int d[501];
bool sol(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		for (int i = 1; i <= N; i++) {
			edge[i].clear();
		}

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			edge[S].push_back({ E, T });
			edge[E].push_back({ S, T });
		}

		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			edge[S].push_back({ E, -T });
		}

		if (sol(1)) { cout << "YES\n"; }
		else { cout << "NO\n"; }
	}
}

bool sol(int start) {
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	d[start] = 0;

	bool cycle;
	for (int i = 1; i <= N; i++) {
		cycle = false;
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < (int)edge[j].size(); k++) {
				int next = edge[j][k].first;
				int cost = edge[j][k].second;
				if (d[next] > d[j] + cost) {
					if (next == start) { return true; }
					d[next] = d[j] + cost;
					cycle = true;
				}
			}
		}
		if (!cycle) { return false; }
	}
	return cycle;
}