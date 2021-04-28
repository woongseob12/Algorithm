#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> in(N + 1), out(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		in[b]++;
	}

	queue<pair<int,int>> q;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) q.push({ i,1 });
	}

	while (!q.empty()) {
		int curr = q.front().first;
		int cnt = q.front().second;
		q.pop();
		out[curr] = max(out[curr], cnt);
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			in[next]--;
			if (in[next] == 0) q.push({ next, cnt + 1 });
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << out[i] << " ";
	}
}