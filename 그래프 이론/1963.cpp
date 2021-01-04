#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool prime[10000];
bool visit[10000];
int bfs(int start, int dest);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;

	for (int i = 2; i < 10000; i++) {
		if (!prime[i]) {
			for (int j = i * i; j < 10000; j += i) {
				prime[j] = true;
			}
		}
	}
	while (TC--) {
		int start, dest, ans;
		cin >> start >> dest;
		ans = bfs(start, dest);
		if (ans == -1) { cout << "Impossible\n"; }
		else { cout << ans << '\n'; }
	}
}

int bfs(int start, int dest) {
	for (int i = 1000; i <= 9999; i++) {
		visit[i] = false;
	}
	queue<pair<int, int>> q;
	q.push({ start,0 });
	while (!q.empty()) {
		int temp = q.front().first;
		int cnt = q.front().second;
		if (temp == dest) {
			return cnt;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			string str = to_string(temp);
			for (int j = 0; j <= 9; j++) {
				str[i] = '0' + j;
				int val = stoi(str);
				if (val >= 1000 && val <= 9999) {
					if (!visit[val] && !prime[val]) {
						q.push({ val, cnt + 1 });
						visit[val] = true;
					}
				}
			}
		}
	}
	return -1;
}
