#include <iostream>
#include <string>
using namespace std;

int N, people, weakness;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };
char map[100][100];
bool v1[100][100];
bool v2[100][100];
void dfs1(int x, int y, char color);
void dfs2(int x, int y, char color);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j];
		}
	}
	// 평범한 사람의 구역
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!v1[i][j]) {
				people++;
				dfs1(i, j, map[i][j]);
			}
		}
	}
	// 적록색약의 구역
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!v2[i][j]) {
				weakness++;
				dfs2(i, j, map[i][j]);
			}
		}
	}
	cout << people << " " << weakness << endl;
}

void dfs1(int x, int y, char color) {
	v1[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nX = x + dx[i], nY = y + dy[i];
		if (nX < 0 || nX >= N || nY < 0 || nY >= N) { continue; } 
		if (!v1[nX][nY] && color == map[nX][nY]) {
			v1[nX][nY] = true;
			dfs1(nX, nY, color);
		}	
	}
}

void dfs2(int x, int y, char color) {
	v2[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nX = x + dx[i], nY = y + dy[i];
		if (nX < 0 || nX >= N || nY < 0 || nY >= N) { continue; }
		if (!v2[nX][nY]) {
			if (color == 'B' && color == map[nX][nY]) {
				v2[nX][nY] = true;
				dfs2(nX, nY, color);
			}
			else if (color != 'B' && map[nX][nY] != 'B') {
				v2[nX][nY] = true;
				dfs2(nX, nY, color);
			}
		}
	}
}