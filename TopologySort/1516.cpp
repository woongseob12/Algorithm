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
	// �ǹ��� ���� ������ ���� �͵��� �̸� �־���
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();		
		int maxTime = 0;

		// ť�� ���� ���� �� �ִ� �ǹ��� �ֱ����� for��
		for (int i = 0; i < seq[curr].size(); i++) {
			int next = seq[curr][i];
			if (--in[next] == 0) {
				q.push(next);
			}
		}

		// �ִ� �ð��� ���ϱ� ���� for��
		for (int i = 0; i < tower[curr].size(); i++) {
			int next = tower[curr][i];
			maxTime = max(maxTime, setup[next]);
		}
		setup[curr] = maxTime + time[curr];
	}

	// ���
	for (int i = 1; i <= n; i++) {
		cout << setup[i] << "\n";
	}
}

int main() {
	input();
	solve();
}