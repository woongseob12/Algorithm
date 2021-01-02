#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool visit[1000001];
int bfs(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> F >> S >> G >> U >> D;
	int ans = bfs(S);
	if (ans == -1) { cout << "use the stairs\n"; }
	else { cout << ans << '\n'; }
}

int bfs(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	visit[start] = true;
	while (!q.empty()) {
		int curr = q.front().first;
		int cnt = q.front().second;
		if (curr == G) { return cnt; }
		q.pop();
		int up = curr + U;
		if (up <= F && !visit[up]) {
			q.push({ up, cnt + 1 });
			visit[up] = true;
		}
		int down = curr - D;
		if (down >= 1 && !visit[down]) {
			q.push({ down,cnt + 1 });
			visit[down] = true;
		}
	}
	return -1;
}