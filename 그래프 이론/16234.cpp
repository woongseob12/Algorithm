#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int N, L, R, ans, idx, sum, cnt, avg;
int arr[50][50];
int visit[50][50];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool open(int y, int x);
void dfs(int y, int x);
void movePerson(int idx, int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		idx = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0 && open(i,j)) {
					idx++;
					dfs(i, j);
					avg = sum / cnt;
					movePerson(idx, avg);
					sum = 0;
					cnt = 0;
				}
			}
		}
		if (idx == 0) break;
		ans++;
	}
	cout << ans;
}

bool open(int y, int x) {
	bool ret = false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		int diff = abs(arr[ny][nx] - arr[y][x]);
		if (diff >= L && diff <= R) {
			ret = true;
			break;
		}
	}
	return ret;
}

void dfs(int y, int x) {
	sum += arr[y][x];
	cnt++;
	visit[y][x] = idx;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		int diff = abs(arr[ny][nx] - arr[y][x]);
		if (visit[ny][nx] == 0 && diff >= L && diff <= R) {
			dfs(ny, nx);
		}
	}
}

void movePerson(int idx, int cnt) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == idx) {
				arr[i][j] = cnt;
			}
		}
	}
}
