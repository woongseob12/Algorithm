#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
int arr[20][20];
int dice[4][3];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
vector<int> comm;

void input() {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	comm.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> comm[i];
		comm[i] -= 1;
	}
}

void isZero() {
	if (arr[y][x] == 0) {
		arr[y][x] = dice[3][1];
	}
	else {
		dice[3][1] = arr[y][x];
		arr[y][x] = 0;
	}
}

void moveDice(int i) {
	int temp;
	if (i == 0) {		// 悼率
		temp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = temp;
	}
	else if (i == 1) {	// 辑率
		temp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = temp;
	}
	else if (i == 2) {	// 合率
		temp = dice[0][1];
		for (int cnt = 0; cnt < 3; cnt++) {
			dice[cnt][1] = dice[cnt + 1][1];
		}
		dice[3][1] = temp;
	}
	else if (i == 3) {	// 巢率
		temp = dice[3][1];
		for (int cnt = 3; cnt > 0; cnt--) {
			dice[cnt][1] = dice[cnt - 1][1];
		}
		dice[0][1] = temp;
	}
}

void sol() {
	for (int i = 0; i < k; i++) {
		int ny = y + dy[comm[i]];
		int nx = x + dx[comm[i]];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		moveDice(comm[i]);
		y = ny;
		x = nx;
		isZero();
		cout << dice[1][1] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	input();
	sol();
}

