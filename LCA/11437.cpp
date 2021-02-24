#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int d[50001], parent[50001], visit[50001];
void dfs(int node, int depth);
int lca(int a, int b);
vector<int> tree[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout <<lca(a, b) << "\n"; 
	}
}

void dfs(int node, int depth) {
	d[node] = max(d[node], depth);
	visit[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		if (!visit[tree[node][i]]) {
			parent[tree[node][i]] = node;
			visit[tree[node][i]] = true;
			dfs(tree[node][i], depth + 1);
		}
	}
}

int lca(int a, int b) {
	while (d[a] != d[b]) {
		if (d[a] < d[b]) {
			b = parent[b];
		}
		else {
			a = parent[a];
		}
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}