#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8];
int res[8];
bool visit[8];
void dfs(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	dfs(0);
}

void dfs(int cnt) {
	if (cnt == M) {
		for(int i = 0; i < M; i++) {
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}

	bool used[10001] = { false, };
	for (int i = 0; i < N; i++) {
		if (!visit[i] && !used[num[i]]) {
			visit[i] = true;
			used[num[i]] = true;
			res[cnt] = num[i];
			if (cnt == 0) {
				dfs(cnt + 1);
			}
			else{
				if (res[cnt - 1] <= res[cnt]) {
					dfs(cnt + 1);
				}
			}
			visit[i] = false;
		}
	}
}