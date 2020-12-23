#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, ans;
int ary[8];
int num[8];
bool visit[8];
void dfs(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	dfs(0);
	cout << ans << endl;
}

void dfs(int cnt) {
	if (cnt == N) {
		int temp = 0;
		for (int i = 0; i < N - 1; i++) {
			temp += abs(ary[num[i]] - ary[num[i + 1]]);
		}
		if (temp > ans) { ans = temp; }
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			num[cnt] = i;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}