#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int N, M, ans;
int parent[MAX];
vector<pair<int, pair<int, int>>> E;
int find(int node);
void merge(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		E.push_back({ c, {a, b} });
	}

	int cnt = N - 1;
	sort(E.begin(), E.end());
	for (int i = 0; i < (int)E.size(); i++) {
		if (find(E[i].second.first) != find(E[i].second.second)) {
			merge(E[i].second.first, E[i].second.second);
			ans += E[i].first;
			cnt--;
			if (cnt == 0) { break; }
		}
	}
	cout << ans << '\n';
}

int find(int node) {
	if (parent[node] == node) { return node; }
	return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) { parent[b] = a; }
	else { parent[a] = b; }
}