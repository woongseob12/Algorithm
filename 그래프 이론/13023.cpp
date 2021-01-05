#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool ans;
vector<int> relation[2000];
bool visit[2000];
void dfs(int start, int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2000; j++) {
			visit[j] = false;
		}
		visit[i] = true;
		dfs(i, 0);
		if (ans) { break; }
	}
	if (ans) { cout << 1; }
	else { cout << 0; }
}

void dfs(int start, int cnt) {
	if (cnt == 4) {
		ans = true;
		return;
	}
	for (int i = 0; i < (int)relation[start].size(); i++) {
		if (!visit[relation[start][i]]) {
			visit[relation[start][i]] = true;
			dfs(relation[start][i], cnt + 1);
			visit[relation[start][i]] = false;
		}
	}
}