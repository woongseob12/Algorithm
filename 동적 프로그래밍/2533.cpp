#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<int> tree[1000001];
int dp[1000001][2];
bool visit[1000001];
void dfs(int node);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}

void dfs(int node) {
	if (dp[node][0] != -1) {
		return;
	}
	dp[node][0] = 0;
	dp[node][1] = 1;
	visit[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (!visit[next]) {
			dfs(next);
			dp[node][0] += dp[next][1];
			dp[node][1] += min(dp[next][0], dp[next][1]);
		}
	}
}
