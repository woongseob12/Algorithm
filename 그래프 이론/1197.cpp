#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAX 10001
using namespace std;

int V, E;
int parent[MAX];
vector<pair<int, pair<int, int>>> edge;
int find(int node);
void merge(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edge.push_back({ C,{A,B} });
	}
	sort(edge.begin(), edge.end());

	int cnt = V - 1;
	int ans = 0;
	for (int i = 0; i < (int)edge.size(); i++) {
		if (find(edge[i].second.first) != find(edge[i].second.second)) {
			merge(edge[i].second.first, edge[i].second.second);
			ans += edge[i].first;
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