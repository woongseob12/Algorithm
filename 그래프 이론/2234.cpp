#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, numOfRoom;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
int arr[50][50];
int num[50][50];
bool visit[50][50];
vector<int> roomSize;
int dfs(int y, int x);
int delWall();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;;
				numOfRoom++;
				roomSize.push_back(dfs(i, j));
			}
		}
	}

	int maxRoom = 0;
	for (int i = 0; i < roomSize.size(); i++) {
		if (maxRoom < roomSize[i]) {
			maxRoom = roomSize[i];
		}
	}

	cout << numOfRoom << '\n'<< maxRoom << '\n'<< delWall() << '\n';
}

int dfs(int y, int x) {
	int rSize = 1;
	num[y][x] = numOfRoom;
	for (int i = 0; i < 4; i++) {
		if (arr[y][x] & (1 << i)) { continue; }
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) { continue; }
		if (!visit[ny][nx]) {
			visit[ny][nx] = true;
			rSize += dfs(ny, nx);
		}
	}
	return rSize;
}

int delWall() {
	int ret = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= m || nx >= n) { continue; }
				if (num[i][j] != num[ny][nx]) {
					ret = max(ret, roomSize[num[i][j] - 1] + roomSize[num[ny][nx] - 1]);
				}
			}
		}
	}
	return ret;
}
