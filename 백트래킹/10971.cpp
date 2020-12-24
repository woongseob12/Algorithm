#include <iostream>
#define INF 987654321
using namespace std;

int N, ans = INF;
int tsp[10][10];
int ary[10];
bool visit[10];
void dfs(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tsp[i][j];
		}
	}
	dfs(0);
	cout << ans << '\n';
}

void dfs(int cnt) {
	if (cnt == N) {
		bool valid = true;
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				if (tsp[ary[i]][ary[0]] == 0) {
					valid = false;
					break;
				}
				temp += tsp[ary[i]][ary[0]];
			}
			else {
				if (tsp[ary[i]][ary[i + 1]] == 0) {
					valid = false;
					break;
				}
				temp += tsp[ary[i]][ary[i + 1]];
			}
		}
		if (valid && ans > temp) { ans = temp; }
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ary[cnt] = i;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}