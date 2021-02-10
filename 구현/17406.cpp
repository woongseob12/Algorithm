#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100
#define INF 987654321
using namespace std;

int N, M, K, r, c, s, loop;
int ary[MAX + 1][MAX + 1];
int origin[MAX + 1][MAX + 1];
bool visit[6]; 
int num[6];
priority_queue <int, vector<int>, greater<>> pq;
vector<vector<int>> kAry;
void changeAry(int sy, int sx, int ey, int ex);
void comb(int cnt);
void cal();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> ary[i][j];
			origin[i][j] = ary[i][j];
		}
	}

	kAry.resize(K);
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		kAry[i] = { r,c,s };
	}
	comb(0);
	cal();
	cout << pq.top();
}

void changeAry(int sy, int sx, int ey, int ex) {
	int temp[4] = { ary[sy][ex], ary[ey][ex], ary[ey][sx], ary[sy][sx] };
	// 오른쪽
	for (int j = ex; j > sx; j--) {
		ary[sy][j] = ary[sy][j - 1];
	}
	// 아래쪽
	for (int i = ey; i > sy; i--) {
		ary[i][ex] = ary[i - 1][ex];
	}
	// 왼쪽
	for (int j = sx; j < ex; j++) {
		ary[ey][j] = ary[ey][j + 1];
	}
	// 위쪽
	for (int i = sy; i < ey; i++) {
		ary[i][sx] = ary[i + 1][sx];
	}
	if (sy != ey) {
		ary[sy + 1][ex] = temp[0];
		ary[ey][ex - 1] = temp[1];
		ary[ey - 1][sx] = temp[2];
		ary[sy][sx + 1] = temp[3];
	}
}

void comb(int cnt) {
	if (cnt == K) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				ary[i][j] = origin[i][j];
			}
		}
		for (int i = 0; i < K; i++) {
			r = kAry[num[i]][0];
			c = kAry[num[i]][1];
			s = kAry[num[i]][2];
			for (int j = 0; j < s; j++) {
				changeAry(r - s + j, c - s + j, r + s - j, c + s - j);
			}
		}
		cal();
		return;
	}

	for (int i = 0; i < (int)kAry.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			num[cnt] = i;
			comb(cnt + 1);
			visit[i] = false;
		}
	}
}

void cal() {
	int ans = INF;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= M; j++) {
			temp += ary[i][j];
		}
		ans = min(ans, temp);
		pq.push(ans);
	}
}
