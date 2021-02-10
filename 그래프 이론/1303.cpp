#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N, M, W, B;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
char ary[101][101];
bool visit[101][101];
int dfs(int i, int j);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			ary[i][j] = s[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				if (ary[i][j] == 'W') {
					W += pow(dfs(i, j),2);
				}
				else {
					B += pow(dfs(i, j), 2);
				}
				
			}
		}
	}
	cout << W << " " << B;
}

int dfs(int y, int x) {
	int cnt = 1;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
		if (!visit[ny][nx] && ary[ny][nx] == ary[y][x]) {
			cnt += dfs(ny, nx);
		}
	}
	return cnt;
}