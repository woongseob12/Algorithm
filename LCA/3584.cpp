#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> tree[10001];
int parent[10001];
int depth[10001];
int n1, n2, N;
void dfs(int node, int cnt);
int lca(int n1, int n2);
void init();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		init();

		for (int i = 0; i < N - 1; i++) {
			int A, B;
			cin >> A >> B;
			tree[A].push_back(B);
			parent[B] = A;
		}
		cin >> n1 >> n2;

		// ±Ì¿Ã º≥¡§
		for (int i = 1; i <= N; i++) {
			if (parent[i] == 0) {
				dfs(i, 0);
			}
		}

		int ans = lca(n1, n2);
		cout << ans << '\n';
	}
}

void dfs(int node, int cnt) {
	if (cnt > depth[node]) {
		depth[node] = cnt;
	}
	for (int i = 0; i < tree[node].size(); i++) {
		dfs(tree[node][i], cnt + 1);
	}
}

int lca(int n1, int n2) {
	while (depth[n1] != depth[n2]) {
		if (depth[n1] > depth[n2]) {
			n1 = parent[n1];
		}
		else {
			n2 = parent[n2];
		}
	}
	while (n1 != n2) {
		n1 = parent[n1];
		n2 = parent[n2];
	}
	return n1;
}

void init() {
	for (int i = 1; i <= N; i++) {
		tree[i].clear();
	}
	memset(depth, 0, sizeof(depth));
	memset(parent, 0, sizeof(parent));
}