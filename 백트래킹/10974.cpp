#include <iostream>
using namespace std;

int N;
int ary[8];
bool visit[8];
void dfs(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	dfs(0);
}

void dfs(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			cout << ary[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			ary[cnt] = i + 1;
			visit[i] = true;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}