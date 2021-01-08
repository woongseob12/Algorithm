#include <iostream>
#include <queue>
using namespace std;

int N, M;
typedef struct POS {
	int y;
	int x;
}Pos;

bool operator==(Pos a, Pos b) {
	return a.x == b.x && a.y == b.y;
}

Pos red, blue, hole;
char map[10][10];
bool visit[10][10][10][10];
Pos d[] = { {1,0},{-1,0},{0,1},{0,-1} };
int bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'R' || map[i][j] == 'B') {
				map[i][j] == 'R' ? red = { i,j } : blue = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'O') {
				hole = { i,j };
			}
		}
	}
	cout << bfs();
}

int bfs() {
	queue<pair<pair<Pos, Pos>, int>> q;
	q.push({ { red,blue }, 0 });
	visit[red.y][red.x][blue.y][blue.x] = true;
	while (!q.empty()) {
		Pos cr = q.front().first.first;
		Pos cb = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (cnt > 10) { break; }
		if (cb == hole) { continue; }
		if (cr == hole) { return cnt; }
		
		for (int i = 0; i < 4; i++) {
			Pos nr = cr;
			bool isWall = false;
			while (map[nr.y][nr.x] != '#' && map[nr.y][nr.x] != 'O') {
				nr.y += d[i].y;
				nr.x += d[i].x;
			}
			if (map[nr.y][nr.x] == '#') { isWall = true; }
			if (map[nr.y][nr.x] != 'O') {
				nr.y -= d[i].y;
				nr.x -= d[i].x;
			}

			Pos nb = cb;
			while (map[nb.y][nb.x] != '#' && map[nb.y][nb.x] != 'O') {
				nb.y += d[i].y;
				nb.x += d[i].x;
			}
			if (map[nb.y][nb.x] == '#') { isWall = true; }
			if (map[nb.y][nb.x] != 'O') {
				nb.y -= d[i].y;
				nb.x -= d[i].x;
			}

			if (nr == nb && isWall) {
				switch (i)
				{
				case 0:
					cr.y > cb.y ? nb.y-- : nr.y--;
					break;
				case 1:	
					cr.y > cb.y ? nr.y++ : nb.y++;
					break;
				case 2:
					cr.x > cb.x ? nb.x-- : nr.x--;
					break;
				case 3:
					cr.x > cb.x ? nr.x++ : nb.x++;
					break;
				}
			}
			if (!visit[nr.y][nr.x][nb.y][nb.x]) {
				q.push({ { nr, nb }, cnt + 1 });
				visit[nr.y][nr.x][nb.y][nb.x] = true;
			}
		}	
	}
	return -1;
}
