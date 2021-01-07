#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ary[8];
int res[8];
void dfs(int idx, int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> ary[i];
	}
	sort(ary, ary + N);
	dfs(0, 0);
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; ++i) {
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; ++i) {
		res[cnt] = ary[i];
		dfs(i + 1, cnt + 1);
	}
}