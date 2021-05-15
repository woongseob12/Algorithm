#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int time[501];
int in[501];
int setup[501];
vector<int> tower[501], seq[501];

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		while (true) {
			int pre;
			cin >> pre;
			if (pre == -1) break;
			in[i]++;
			tower[i].push_back(pre);
			seq[pre].push_back(i);
		}
	}
}

void solve() {
	queue<int> q;
	// 건물을 짓는 조건이 없는 것들을 미리 넣어줌
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();		
		int maxTime = 0;

		// 큐에 다음 지을 수 있는 건물을 넣기위한 for문
		for (int i = 0; i < seq[curr].size(); i++) {
			int next = seq[curr][i];
			if (--in[next] == 0) {
				q.push(next);
			}
		}

		// 최대 시간을 구하기 위한 for문
		for (int i = 0; i < tower[curr].size(); i++) {
			int next = tower[curr][i];
			maxTime = max(maxTime, setup[next]);
		}
		setup[curr] = maxTime + time[curr];
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		cout << setup[i] << "\n";
	}
}

int main() {
	input();
	solve();
}