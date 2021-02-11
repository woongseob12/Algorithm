#include <iostream>
using namespace std;

int N, M, r, c, d, ans, nr, nc;
bool flag;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int ary[50][50];
bool visit[50][50];
void clean1();
bool clean2();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ary[i][j];
		}
	}
	while (1) {
		if (!flag) {
			clean1();
		}
		
		if (clean2()) {
			break;
		}
	}
	
	cout << ans;
}

void clean1() {
	if (ary[r][c] == 1 || visit[r][c]) {
		return;
	}
	visit[r][c] = true;
	ans++;
	flag = true;
}

bool clean2() {
	for (int i = 0; i < 4; i++) {
		d--;
		if (d < 0) { d = 3; }
		nr = r + dr[d];
		nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < N && nc < M && !visit[nr][nc] && ary[nr][nc] != 1) {
			r = nr;
			c = nc;
			flag = false;
			return false;
		}
	}

	nr = r - dr[d];
	nc = c - dc[d];
	if (nr >= 0 && nc >= 0 && nr < N && nc < M && ary[nr][nc] != 1) {
		r = nr;
		c = nc;
		return false;
	}
	return true;
}
