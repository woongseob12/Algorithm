#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, ans;
int map[100][100];
bool visit[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y, int h);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int minRainfall = INF, maxRainfall = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			minRainfall = min(minRainfall, map[i][j]);
			maxRainfall = max(maxRainfall, map[i][j]);
		}
	}

	for (int k = minRainfall - 1; k < maxRainfall; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
			}
		}
		int temp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && map[i][j] > k) {
					temp++;
					dfs(i, j, k);
				}
			}
		}
		ans = max(ans, temp);
	}
	cout << ans << endl;
}

void dfs(int x, int y, int h) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) { continue; }
		if (!visit[nx][ny] && map[nx][ny] > h) {
			dfs(nx, ny, h);
		}
	}
}