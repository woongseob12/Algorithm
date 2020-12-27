#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ary[8];
int res[8];
bool visit[8];
void dfs(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	sort(ary, ary + N);
	dfs(0);
}

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		res[cnt] = ary[i];
		if (cnt > 0 && res[cnt] < res[cnt - 1]) { continue; }
		dfs(cnt + 1);

	}
}