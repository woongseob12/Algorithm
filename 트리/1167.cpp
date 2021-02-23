#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int V, len, r;
bool visit[100001];
vector<pair<int, int>> tree[100001];
void dfs(int curr, int sum);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V;
	for (int i = 1; i <= V; i++) {
		int curr, next;
		cin >> curr >> next;
		while (next != -1) {
			int dist;
			cin >> dist;
			tree[curr].push_back({ next, dist });
			cin >> next;
		}
	}

	dfs(1, 0);
	memset(visit, false, sizeof(visit));
	dfs(r, 0);
	cout << len << '\n';
}

void dfs(int curr, int sum) {
	visit[curr] = true;
	if (len < sum) {
		len = sum;
		r = curr;
	}
	for (int i = 0; i < (int)tree[curr].size(); i++) {
		if (!visit[tree[curr][i].first]) {
			dfs(tree[curr][i].first, sum + tree[curr][i].second);
		}
	}
}