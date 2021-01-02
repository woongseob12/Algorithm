#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char alpha[15];
char res[15];
bool visit[15];
void dfs(int m, int j, int idx, int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}
	sort(alpha, alpha + C);

	dfs(0, 0, 0, 0);
}

void dfs(int m, int j, int idx, int cnt) {
	if (cnt == L) {
		if (m >= 1 && j >= 2) {
			for (int i = 0; i < L; i++) {
				cout << res[i];
			}
			cout << "\tm: " << m << "\tj: " << j << '\n';
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		if (!visit[i]) {
			visit[i] = true;
			res[cnt] = alpha[i];
			if (res[cnt] == 'a' || res[cnt] == 'e' || res[cnt] == 'i' || res[cnt] == 'o' || res[cnt] == 'u') {
				dfs(m + 1, j, i + 1, cnt + 1);
			}
			else {
				dfs(m, j + 1, i + 1, cnt + 1);
			}
			visit[i] = false;
		}
	}
}