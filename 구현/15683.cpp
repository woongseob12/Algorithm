#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = 987654321, numOfCam;
char map[8][8];
vector<pair<pair<int, int>, char>> cam;
int dir[8];
int type[8];
void sel(int cnt);
void sol();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != '0' && map[i][j] != '6') {
				type[numOfCam++] = map[i][j] - '0';
				cam.push_back({ { i,j },map[i][j] });
			}
		}
	}
	sel(0);

	cout << ans << "\n";
}

void sel(int cnt) {
	if (cnt == numOfCam) {
		sol();
		return;
	}
	// 방향 잡기
	if (type[cnt] == 1) {
		for (int i = 0; i < 4; i++) {
			dir[cnt] = i;
			sel(cnt + 1);
		}
	}
	else if (type[cnt] == 2) {
		for (int i = 0; i < 2; i++) {
			dir[cnt] = i;
			sel(cnt + 1);
		}
	}
	else if (type[cnt] == 3) {
		for (int i = 0; i < 4; i++) {
			dir[cnt] = i;
			sel(cnt + 1);
		}
	}
	else if (type[cnt] == 4) {
		for (int i = 0; i < 4; i++) {
			dir[cnt] = i;
			sel(cnt + 1);
		}
	}
	else if (type[cnt] == 5) {
		sel(cnt + 1);
	}
}

void sol() {
	char arr[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < (int)cam.size(); i++) {
		// 1번 카메라
		if (cam[i].second == '1') {
			int ny = cam[i].first.first;
			int nx = cam[i].first.second;
			if (dir[i] == 0) {
				while (true) {
					ny += 1;
					if (ny >= N || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else if (dir[i] == 1) {
				while (true) {
					nx += 1;
					if (nx >= M || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else if (dir[i] == 2) {
				while (true) {
					ny -= 1;
					if (ny < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else if (dir[i] == 3) {
				while (true) {
					nx -= 1;
					if (nx < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
		}
		// 2번 카메라
		else if (cam[i].second == '2') {
			int ny = cam[i].first.first;
			int nx = cam[i].first.second;
			if (dir[i] == 0) {
				// 상, 하
				while (true) {
					ny += 1;
					if (ny >= N || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				while (true) {
					ny -= 1;
					if (ny < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else {
				// 좌, 우
				while (true) {
					nx += 1;
					if (nx >= M || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				while (true) {
					nx -= 1;
					if (nx < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
		}
		// 3번 카메라
		else if (cam[i].second == '3') {
			int ny = cam[i].first.first;
			int nx = cam[i].first.second;
			if (dir[i] == 0) {
				// 상, 우
				while (true) {
					ny += 1;
					if (ny >= N || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					nx += 1;
					if (nx >= M || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else if (dir[i] == 1) {
				// 우, 하
				while (true) {
					nx += 1;
					if (nx >= M || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					ny -= 1;
					if (ny < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else if (dir[i] == 2) {
				// 하, 좌
				while (true) {
					ny -= 1;
					if (ny < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					nx -= 1;
					if (nx < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else if (dir[i] == 3) {
				// 좌, 상
				while (true) {
					nx -= 1;
					if (nx < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					ny += 1;
					if (ny >= N || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
		}
		// 4번 카메라
		else if (cam[i].second == '4') {
			int ny = cam[i].first.first;
			int nx = cam[i].first.second;
			if (dir[i] == 0) {
				// 상
				while (true) {
					ny += 1;
					if (ny >= N || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				// 우
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					nx += 1;
					if (nx >= M || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				// 하
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					ny -= 1;
					if (ny < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else if (dir[i] == 1) {
				// 우
				while (true) {
					nx += 1;
					if (nx >= M || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				// 하
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					ny -= 1;
					if (ny < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				// 좌
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					nx -= 1;
					if (nx < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else if (dir[i] == 2) {
				// 상
				while (true) {
					ny += 1;
					if (ny >= N || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				// 하
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					ny -= 1;
					if (ny < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				// 좌
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					nx -= 1;
					if (nx < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			else {
				// 상
				while (true) {
					ny += 1;
					if (ny >= N || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
				// 우
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					nx += 1;
					if (nx >= M || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}

				// 좌
				ny = cam[i].first.first;
				nx = cam[i].first.second;
				while (true) {
					nx -= 1;
					if (nx < 0 || arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
		}
		else if (cam[i].second == '5') {
			int ny = cam[i].first.first;
			int nx = cam[i].first.second;
			while (true) {
				ny += 1;
				if (ny >= N || arr[ny][nx] == '6') break;
				if (arr[ny][nx] == '0') arr[ny][nx] = '#';
			}
			// 우
			ny = cam[i].first.first;
			nx = cam[i].first.second;
			while (true) {
				nx += 1;
				if (nx >= M || arr[ny][nx] == '6') break;
				if (arr[ny][nx] == '0') arr[ny][nx] = '#';
			}
			// 하
			ny = cam[i].first.first;
			nx = cam[i].first.second;
			while (true) {
				ny -= 1;
				if (ny < 0 || arr[ny][nx] == '6') break;
				if (arr[ny][nx] == '0') arr[ny][nx] = '#';
			}
			// 좌
			ny = cam[i].first.first;
			nx = cam[i].first.second;
			while (true) {
				nx -= 1;
				if (nx < 0 || arr[ny][nx] == '6') break;
				if (arr[ny][nx] == '0') arr[ny][nx] = '#';
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '0') {
				temp++;
			}
		}
	}
	ans = min(ans, temp);
}
