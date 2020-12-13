#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int map[500][500];
int t_1(int y, int x);
int t_2(int y, int x);
int t_3(int y, int x);
int t_4(int y, int x);
int t_5(int y, int x);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = max(ans, t_1(i, j));
			ans = max(ans, t_2(i, j));
			ans = max(ans, t_3(i, j));
			ans = max(ans, t_4(i, j));
			ans = max(ans, t_5(i, j));
		}
	}
	cout << ans << endl;
}

int t_1(int y, int x) {
	int sum = 0;
	if (x >= 0 && x + 3 < M) {
		sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y][x + 3];
	}
	if (y >= 0 && y + 3 < N) {
		sum = max(sum,map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 3][x]);
	}
	return sum;
}

int t_2(int y, int x) {
	int sum = 0;
	if (x >= 0 && y >= 0 && x + 1 < M && y + 1 < N) {
		sum = map[y][x] + map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1];
	}
	return sum;
}

int t_3(int y, int x) {
	int sum = 0;
	if (x >= 0 && y >= 0 && x + 2 < M && y + 1 < N) {
		sum = max(sum, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x]);
		sum = max(sum, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 2]);
		sum = max(sum, map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2] + map[y][x + 2]);
		sum = max(sum, map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2]);
	}
	if (x >= 0 && y >= 0 && x + 1 < M && y + 2 < N) {
		sum = max(sum, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x + 1]);
		sum = max(sum, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y][x + 1]);
		sum = max(sum, map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1]);
		sum = max(sum, map[y + 2][x] + map[y + 2][x + 1] + map[y + 1][x + 1] + map[y][x + 1]);
	}
	return sum;
}

int t_4(int y, int x) {
	int sum = 0;
	if (x >= 0 && y >= 0 && x + 2 < M && y + 1 < N) {
		sum = max(sum, map[y][x + 1] + map[y][x + 2] + map[y + 1][x] + map[y + 1][x + 1]);
		sum = max(sum, map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2]);
	}
	if (x >= 0 && y >= 0 && x + 1 < M && y + 2 < N) {
		sum = max(sum, map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1]);
		sum = max(sum, map[y + 1][x] + map[y + 2][x] + map[y][x + 1] + map[y + 1][x + 1]);
	}
	return sum;
}

int t_5(int y, int x) {
	int sum = 0;
	if (x >= 0 && y >= 0 && x + 2 < M && y + 1 < N) {
		sum = max(sum, map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2]);
		sum = max(sum, map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y][x + 2]);
	}
	if (x >= 0 && y >= 0 && x + 1 < M && y + 2 < N) {
		sum = max(sum, map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x]);
		sum = max(sum, map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1]);
	}
	return sum;
}