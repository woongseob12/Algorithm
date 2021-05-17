#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef struct Data {
	string a;
	string b;
	string c;
}Data;
int n;
queue<pair<int, int>> q;
bool visit[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string a, b, c;
		cin >> a >> b >> c;
		bool flag = false;
		q = queue<pair<int, int>>();
		memset(visit, false, sizeof(visit));

		if (c[0] == a[0]) {
			q.push({ 1, 0 });
			visit[1][0] = true;
		}
		if (c[0] == b[0]) {
			q.push({ 0, 1 });
			visit[0][1] = true;
		}

		while (!q.empty()) {
			int aIdx = q.front().first;
			int bIdx = q.front().second;
			q.pop();
			if (aIdx == a.size() && bIdx == b.size()) {
				flag = true;
				break;
			}

			if (!visit[aIdx + 1][bIdx] && aIdx + 1 <= a.size() && a[aIdx] == c[aIdx + bIdx]) {
				visit[aIdx + 1][bIdx] = true;
				q.push({ aIdx + 1, bIdx });
			}
			if (!visit[aIdx][bIdx + 1] && bIdx + 1 <= b.size() && b[bIdx] == c[aIdx + bIdx]) {
				visit[aIdx][bIdx + 1] = true;
				q.push({ aIdx, bIdx + 1 });
			}
		}
		cout << "Data set " << i << ": " << (flag?"yes\n":"no\n");
	}
}