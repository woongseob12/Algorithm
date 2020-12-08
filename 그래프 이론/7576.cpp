#include <iostream>
#include <queue>
using namespace std;

int M, N, ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int storage[1000][1000];
bool visit[1000][1000];
queue<pair<pair<int, int>, int>> q;
void init();
void bfs();

int main()
{
	init();
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> storage[i][j];
			if (storage[i][j] == 1) {
				q.push(make_pair(make_pair(i, j), 0));
				visit[i][j] = true;
			}
		}
	}


	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(!visit[i][j] && storage[i][j] == 0){
				ans = -1;
				break;
			}
		}
	}
	cout << ans << endl;
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void bfs()
{
	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		ans = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextRow = row + dy[i], nextCol = col + dx[i];
			if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) { continue; }
			if (!visit[nextRow][nextCol] && storage[nextRow][nextCol] == 0) {
				q.push(make_pair(make_pair(nextRow, nextCol), ans + 1));
				visit[nextRow][nextCol] = true;
			}
		}
	}
}