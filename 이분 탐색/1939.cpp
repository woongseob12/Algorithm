#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define INF 1e9
using namespace std;

int N, M, S, E, ans;
vector<pair<int, int>> graph[MAX];
int cal(int l, int r);
bool bfs(int val);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> S >> E;
	cout << cal(1, INF);
}

int cal(int l, int r) {
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (bfs(mid)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return r;
}

bool bfs(int val) {
	queue<int> q;
	q.push(S);
	vector<bool> visit(N + 1);
	visit[S] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (curr == E) {
			ans = val;
			return true;
		}
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			if (!visit[next] && graph[curr][i].second >= val) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}