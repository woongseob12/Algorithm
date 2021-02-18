#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int R, C, ans;
bool flag;
int dr[] = { -1, 0, 1 };
int dc[] = { 1, 1, 1 };
char arr[10000][500];
bool visit[10000][500];
void sol(int r, int c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			arr[i][j] = s[j];
		}
	}

	for (int i = 0; i < R; i++) {
		flag = false;
		sol(i, 0);
	}
	cout << ans << '\n';
}

void sol(int r, int c) {
	if (c == C -1) {
		flag = true;
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= R) { continue; }
		if (!visit[nr][nc] && arr[nr][nc] != 'x') {
			visit[nr][nc] = true;
			sol(nr, nc);
			if (flag == true)return;
		}
	}
}