#include <iostream>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int field[50][50];
bool visit[50][50];
void init();
void dfs(int i, int j);
int M, N, K;


int main()
{
	init();
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> M >> N >> K;
		// √ ±‚»≠ 
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				field[i][j] = 0;
				visit[i][j] = false;
			}
		}

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 1){
					if (!visit[i][j]) {
						visit[i][j] = true;
						ans++;
						dfs(i, j);
					}
				}
			}
		}
		cout << ans << '\n';
	}
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dfs(int x, int y) 
{
	if (field[x][y] == 0) { return; }

	for (int i = 0; i < 4; i++) {
		int nX = x + dx[i], nY = y + dy[i];
		if (nX < 0 || nX >= N || nY < 0 || nY >= M) { continue; }
		if (!visit[nX][nY]) {
			visit[nX][nY] = true;
			if (field[nX][nY] == 1) {
				dfs(nX, nY);
			}
		}
	}
}