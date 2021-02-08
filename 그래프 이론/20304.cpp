#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<bool> visit;
queue<pair<int, int>> q;
int bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	visit.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int val;
		cin >> val;
		q.push({ val, 0 });
	}
	cout << bfs();
}

int bfs() {
	int num, len = 0;
	while (!q.empty()) {
		num = q.front().first;
		len = q.front().second;
		q.pop();

		// 비트마스킹 처리를 통해 temp값을 설정
		int bitlen = 0, l = N;
		while (l > 1) {
			bitlen++;
			l /= 2;
		}

		for (int i = 0; i <= bitlen; i++) {
			int temp = num ^ (1 << i);
			if (temp <= N &&!visit[temp]) {
				visit[temp] = true;
				q.push({ temp, len + 1 });
			}
		}	
	}
	return len;
}
