#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
vector<int> parent;
int getParent(int x);
void unionParent(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	parent.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int to, from, cost;
		cin >> to >> from >> cost;
		pq.push({ cost,{to, from} });
	}
	int cnt = 0, ans = 0;
	while (cnt != N - 2) {
		int to = pq.top().second.first;
		int from = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (getParent(to) != getParent(from)) {
			unionParent(to, from);
			ans += cost;
			cnt++;
		}
	}
	cout << ans;
}

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}