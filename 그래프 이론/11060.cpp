#include <iostream>
#include <queue>
using namespace std;

int N;
int A[1000];
int bfs(int start);
bool visit[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	cout << bfs(0) << '\n';
}

int bfs(int start) {
	queue<pair<int, int>> q;
	q.push({start, 0});
	visit[start] = true;
	while (!q.empty()) {
		int idx = q.front().first;
		int cnt = q.front().second;
		if (idx == N - 1) { return cnt; }
		q.pop();
		for (int i = 1; i <= A[idx]; ++i) {
			if (idx + i >= N) { continue; }
			if (!visit[idx + i]) {
				visit[idx + i] = true;
				q.push({ idx + i, cnt + 1 });
			}
		}
	}
	return -1;
}