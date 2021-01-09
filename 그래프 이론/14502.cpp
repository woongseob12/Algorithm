#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, ans;
pair<int, int> d[] = { {1,0}, {-1,0}, {0,1},{0,-1} };
int map[8][8];
int virusMap[8][8];
vector<pair<int, int>> virus;

void makeWall(int idx, int cnt);
void makeVirusMap();
int checkArea();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	makeWall(0, 0);
	cout << ans << '\n';
}

void makeWall(int idx, int cnt) {
	if (cnt == 3) {
		makeVirusMap();
		ans = max(ans, checkArea());
		return;
	}

	for (int i = idx; i < N*M; ++i) {
		if (map[i / M][i % M] == 0) {
			map[i / M][i % M] = 1;
			makeWall(i, cnt + 1);
			map[i / M][i % M] = 0;
		}
	}
}

void makeVirusMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			virusMap[i][j] = map[i][j];
		}
	}
}

int checkArea() {
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); ++i) {
		q.push(virus[i]);
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + d[i].first;
			int nx = x + d[i].second;
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (virusMap[ny][nx] == 0) {
				virusMap[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}

	int area = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (virusMap[i][j] == 0) {
				area++;
			}
		}
	}
	return area;
}