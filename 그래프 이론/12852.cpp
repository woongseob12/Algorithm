#include <queue>
#include <iostream>
using namespace std;

int N;
int visit[1000001];
queue<pair<int, int>> q;
int bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	q.push({ 1, 0 });
	int cnt = bfs();
	cout << cnt << "\n" << N << " ";
	while (N > 1) {
		if (N % 3 == 0 && visit[N / 3] == cnt - 1) {
			cout << N / 3 << " ";
			N /= 3;
		}
		else if (N % 2 == 0 && visit[N / 2] == cnt - 1) {
			cout << N / 2 << " ";
			N /= 2;
		}
		else {
			cout << N - 1 << " ";
			N -= 1;
		}
		cnt--;
	}
}

int bfs() {
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == N) {
			return cnt;
		}
		int next = num * 3;
		if (next <= 1000000 && !visit[next]) {
			visit[next] = cnt + 1;
			q.push({ next, cnt + 1 });
		}

		next = num * 2;
		if (next <= 1000000 && !visit[next]) {
			visit[next] = cnt + 1;
			q.push({ next, cnt + 1 });
		}

		next = num + 1;
		if (next <= 1000000 && !visit[next]) {
			visit[next] = cnt + 1;
			q.push({ next, cnt + 1 });
		}
	}
	return -1;
}