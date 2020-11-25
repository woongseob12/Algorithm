#pragma warning (disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int city[25][25];
bool visit[25][25];
void bfs(int x, int y);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &city[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (city[i][j] != 0 && !visit[i][j]) {
				bfs(i, j);
			}
		}
	}

	//단지 수 출력
	cout << ans << endl;

	// 집의 수 세기
	vector<int> num(ans);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (city[i][j] != 0) {
				num[city[i][j] - 1]++;
			}
		}
	}

	// 각 단지내의 집의 수 출력
	sort(num.begin(), num.end());
	for (int i = 0; i < (int)num.size(); i++) {
		cout << num[i] << endl;
	}
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	ans++;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		city[x][y] = ans;
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i], nextY = y + dy[i];
			if ((nextX >= 0 && nextX < N) && (nextY >= 0 && nextY < N)) {
				if ((!visit[nextX][nextY]) && (city[nextX][nextY] != 0)) {
					visit[nextX][nextY] = true;
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}
}