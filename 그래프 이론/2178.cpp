#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M, ans;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int miro[101][101];
int step[101][101];
void bfs(int x, int y);

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			miro[i][j + 1] = s.at(j) - '0';
		}
	}

	bfs(1, 1);
	
	cout << step[N][M] << endl;
}

void bfs(int x, int y)
{
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	step[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if ((nextX > 0 && nextX <= N) && (nextY > 0 && nextY <= M) && (miro[nextX][nextY] == 1)) {
				if (step[nextX][nextY] == 0) {
					q.push(make_pair(nextX, nextY));
					step[nextX][nextY] = step[x][y] + 1;
				}
			}
		}
	}

}