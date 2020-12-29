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
	cout << ans << '\n';
}

void bfs(int n) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ 0, n });
	while (!pq.empty()) {
		int loop = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		if (pos == K) {
			ans = loop;
			break;
		}
		visit[pos] = true;

		int temp;
		temp = pos - 1;
		if (temp >= 0 && !visit[temp]) {
			pq.push({ loop + 1, temp });
		}
		temp = pos + 1;
		if (temp <= 100000 && !visit[temp]) {
			pq.push({ loop + 1, temp });
		}
		temp = pos * 2;
		if (temp <= 100000 && !visit[temp]) {
			pq.push({ loop, temp});
		}
	}
}