#include <iostream>
using namespace std;

int w, h;
pair<int, int> pos[8] = { {1,0},{1,1},{0,1}, {-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
int map[50][50];
bool visit[50][50];
void dfs(int r, int c);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> w >> h;
	while (w != 0 && h != 0) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				visit[i][j] = false;
			}
		}

		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					visit[i][j] = true;
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << '\n';
		cin >> w >> h;
	}
}

void dfs(int r, int c) {
	for (int i = 0; i < 8; i++) {
		int nr = r + pos[i].first, nc = c + pos[i].second;
		if (nr < 0 || nr >= h || nc < 0 || nc >= w) { continue; }
		if (!visit[nr][nc]) {
			visit[nr][nc] = true;
			if (map[nr][nc] == 1) {
				dfs(nr, nc);
			}
		}
	}
}