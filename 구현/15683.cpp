#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = 987654321, numOfCam;
char map[8][8], arr[8][8];
vector<pair<pair<int, int>, char>> cam;
int dir[8], type[8];
void sel(int cnt);
void sol();
void left(int ny, int nx);
void right(int ny, int nx);
void up(int ny, int nx);
void down(int ny, int nx);

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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < (int)cam.size(); i++) {
		int ny = cam[i].first.first;
		int nx = cam[i].first.second;

		if (cam[i].second == '1') {
			switch (dir[i]) {
			case 0:
				up(ny, nx); break;
			case 1:
				right(ny, nx); break;
			case 2:
				down(ny, nx); break;
			case 3:
				left(ny, nx); break;
			}
		}

		else if (cam[i].second == '2') {
			switch (dir[i]) {
			case 0:
				up(ny, nx); down(ny, nx); break;
			case 1:
				left(ny, nx); right(ny, nx); break;
			}
		}

		else if (cam[i].second == '3') {
			switch (dir[i]) {
			case 0:
				up(ny, nx); right(ny, nx); break;
			case 1:
				right(ny, nx); down(ny, nx); break;
			case 2:
				down(ny, nx); left(ny, nx); break;
			case 3:
				left(ny, nx); up(ny, nx); break;
			}
		}

		else if (cam[i].second == '4') {
			switch (dir[i]) {
			case 0:
				up(ny, nx); right(ny, nx); down(ny, nx); break;
			case 1:
				right(ny, nx); down(ny, nx); left(ny, nx); break;
			case 2:
				down(ny, nx); left(ny, nx); up(ny, nx); break;
			case 3:
				left(ny, nx); up(ny, nx); right(ny, nx); break;
			}
		}
		else if (cam[i].second == '5') {
			up(ny, nx);
			right(ny, nx);
			down(ny, nx);
			left(ny, nx);
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

void left(int ny, int nx) {
	while (true) {
		nx -= 1;
		if (nx < 0 || arr[ny][nx] == '6') break;
		if (arr[ny][nx] == '0') arr[ny][nx] = '#';
	}
}

void right(int ny, int nx) {
	while (true) {
		nx += 1;
		if (nx >= M || arr[ny][nx] == '6') break;
		if (arr[ny][nx] == '0') arr[ny][nx] = '#';
	}
}

void up(int ny, int nx) {
	while (true) {
		ny -= 1;
		if (ny < 0 || arr[ny][nx] == '6') break;
		if (arr[ny][nx] == '0') arr[ny][nx] = '#';
	}
}

void down(int ny, int nx) {
	while (true) {
		ny += 1;
		if (ny >= N || arr[ny][nx] == '6') break;
		if (arr[ny][nx] == '0') arr[ny][nx] = '#';
	}
}
