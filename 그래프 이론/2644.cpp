#include <iostream>
#include <queue>
using namespace std;

int N, p1, p2;
bool visit[101];
int family[101][101];
int bfs(int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m;
	cin >> N >> p1 >> p2 >> m;
	
	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;
		family[parent][child] = family[child][parent] = 1;
	}
	cout << bfs(p1) << '\n';
}

int bfs(int n) {
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		if (family[n][i] == 1) {
			visit[i] = true;
			q.push(make_pair(i, 1));
		}
	}
	while (!q.empty()) {
		int idx = q.front().first;
		int cnt = q.front().second;
		if (idx == p2) {
			return cnt;
		}
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visit[i] && family[idx][i] == 1) {
				visit[i] = true;
				q.push(make_pair(i, cnt + 1));
			}
		}
	}
	return -1;
}