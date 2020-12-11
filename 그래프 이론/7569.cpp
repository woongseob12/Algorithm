#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, H, day;
int dd[6] = { 1, -1, 0, 0, 0, 0 };
int dr[6] = { 0, 0, 1, -1, 0, 0 };
int dc[6] = { 0, 0, 0, 0, 1, -1 };
int tomato[100][100][100];
bool visit[100][100][100];
queue<pair<vector<int>, int>> q;
void bfs();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					vector<int> temp = { i,j,k };
					q.push(make_pair(temp, 0));
					visit[i][j][k] = true;
				}
			}
		}
	}
	bfs();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[i][j][k] == 0 && !visit[i][j][k]) {
					day = -1;
				}
			}
		}
	}
	cout << day << endl;
}

void bfs() {
	while (!q.empty()) {
		int dim = q.front().first[0], row = q.front().first[1], col = q.front().first[2];
		day = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nextDim = dim + dd[i], nextRow = row + dr[i], nextCol = col + dc[i];
			if (nextDim < 0 || nextDim >= H || nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) { continue; }
			if (tomato[nextDim][nextRow][nextCol] == 0 && !visit[nextDim][nextRow][nextCol]) {
				vector<int> temp = { nextDim, nextRow, nextCol };
				q.push(make_pair(temp, day + 1));
				visit[nextDim][nextRow][nextCol] = true;
			}
		}
	}
}