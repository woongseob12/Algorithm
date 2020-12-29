#include <iostream>
#include <queue>
using namespace std;

int N, K, ans, cnt;
bool visit[100001];
void bfs(int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;

	bfs(N);
	cout << ans << '\n' << cnt;
}

void bfs(int n) {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	while (!q.empty()) {
		int pos = q.front().first;
		int loop = q.front().second;
		if (ans != 0 && loop > ans) {
			break;
		}
		q.pop();
		if (pos == K) {
			ans = loop;
			cnt++;
		}
		visit[pos] = true;

		int temp;
		temp = pos - 1;
		if (temp >= 0 && !visit[temp]) {
			q.push({ temp, loop + 1 });
		}
		temp = pos + 1;
		if (temp <= 100000 && !visit[temp]) {
			q.push({ temp, loop + 1 });
		}
		temp = pos * 2;
		if (temp <= 100000 && !visit[temp]) {
			q.push({ temp, loop + 1 });
		}
	}
}