#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, d, r1, r2;
vector<pair<int,int>> tree[10001];
bool visit[10001];
void dfs(int node, int dist);

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int p, c, w;
		cin >> p >> c >> w;
		tree[p].push_back({ c, w });
		tree[c].push_back({ p, w });
	}

	dfs(1, 0);
	memset(visit, false, sizeof(visit));
	dfs(r1, 0);
	cout << d;
}

void dfs(int node, int dist) {
	visit[node] = true;
	if (d < dist) {
		d = dist;
		r1 = node;
	}
	for (int i = 0; i < tree[node].size(); i++) {
		if (!visit[tree[node][i].first]) {
			dfs(tree[node][i].first, dist + tree[node][i].second);
		}
	}
}
