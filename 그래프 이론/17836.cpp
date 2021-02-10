#include <iostream>
#include <queue>
using namespace std;

int N, M, T;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
bool visit[2][100][100];
int ary[100][100];
int bfs();

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ary[i][j];
		}
	}
	
	int life = bfs();
	if (life <= T) {
		cout << life;
	}
	else {
		cout << "Fail";
	}
}

int bfs() {
	queue<pair<pair<int, int>, pair<int, bool>>> q;
	q.push({ { 0,0 }, { 0 , false } });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int time = q.front().second.first;
		bool sword = q.front().second.second;
		q.pop();
		if (y == N - 1 && x == M - 1) {
			return time;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) { continue; }
			if (sword) {
				if (!visit[1][ny][nx]) {
					visit[1][ny][nx] = true;
					q.push({ { ny,nx }, { time + 1 , sword } });
				}
			}
			else {
				if (!visit[0][ny][nx] && ary[ny][nx] != 1) {
					visit[0][ny][nx] = true;
					if (ary[ny][nx] == 2) {
						q.push({ { ny,nx }, { time + 1 , true } });
					}
					else {
						q.push({ { ny,nx }, { time + 1 , false } });
					}
				}
			}
		}
	}
	return T + 1;
}