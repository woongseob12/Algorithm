#include <iostream>
#include <string>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0, 0 };
int map[100][100];
int d[100][100];
void sol(int y, int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j] - '0';
			d[i][j] = INF;
		}
	}
	sol(0, 0);
	cout << d[N - 1][M - 1];
}

void sol(int y, int x) {
	d[y][x] = map[y][x];
	queue<pair<int, int>> q;
	q.push({y,x});
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (d[ny][nx] > d[y][x] + map[ny][nx]) {
				d[ny][nx] = d[y][x] + map[ny][nx];
				q.push({ny, nx});
			}
		}
	}
}