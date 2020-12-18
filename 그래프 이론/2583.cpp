#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K, cnt;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[100][100];
bool visit[100][100];
void coloring(int leftX, int leftY, int rightX, int rightY);
void dfs(int y, int x);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int leftX, leftY, rightX, rightY;
		cin >> leftX >> leftY >> rightX >> rightY;
		coloring(leftX, leftY, rightX, rightY);
	}

	vector<int> ans;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}
}

void coloring(int leftX, int leftY, int rightX, int rightY) {
	for (int i = leftY; i < rightY ; i++) {
		for (int j = leftX; j < rightX; j++) {
			map[i][j] = 1;
		}
	}
}

void dfs(int y, int x) {
	visit[y][x] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) { continue; }
		if (!visit[ny][nx] && map[ny][nx] == 0) {
			visit[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}