#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D, ans;
int dy[] = { 0, 1,0,-1 };
int dx[] = { -1,0,1,0 };
int arr[15][15], cArr[15][15];
vector<pair<int, int>> enemy, archer(3);
bool visit[15];
void comb(int cnt, int idx);
int cal();

typedef struct _Info {
	int y;
	int x;
	int d;

}Info;

bool cmp(Info o1, Info o2) {
	if (o1.d == o2.d) {
		return o1.x < o2.x;
	}
	return o1.d < o2.d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	comb(0, 0);
	cout << ans << '\n';
}

void comb(int cnt, int idx) {
	if (cnt == 3) {
		ans = max(ans, cal());
		return;
	}

	for (int i = idx; i < M; i++) {
		archer[cnt].first = N;
		archer[cnt].second = i;
		comb(cnt + 1, i + 1);
	}
	return;
}

int cal() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cArr[i][j] = arr[i][j];
		}
	}
	int kill = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cArr[i][j] == 1) {
				enemy.push_back({ i, j });
			}
		}
	}

	while (!enemy.empty()) {
		//	1. 공격 받고
		vector<Info> canKill, temp;
		for (int i = 0; i < 3; i++) {
			temp.clear();
			for (int j = 0; j < (int)enemy.size(); j++) {
				int dist = (archer[i].first - enemy[j].first) + abs(archer[i].second - enemy[j].second);
				if (dist <= D) {
					temp.push_back({ enemy[j].first, enemy[j].second, dist });
				}
			}
			if (temp.size() > 1) {
				sort(temp.begin(), temp.end(), cmp);
			}
			if (!temp.empty()) {
				canKill.push_back(temp[0]);
			}
		}
		//	2. 공격 받은 적 게임에서 제외 시키고
		for (int i = 0; i < (int)canKill.size(); i++) {
			if (cArr[canKill[i].y][canKill[i].x] == 1) {
				cArr[canKill[i].y][canKill[i].x] = 0;
				kill++;
			}
		}
		canKill.clear();
		//  3. 적은 아래로 이동
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (i == 0) {
					cArr[i][j] = 0;
				}
				else {
					cArr[i][j] = cArr[i - 1][j];
				}
			}
		}
		//	4. 적이 없으면 게임 끝
		enemy.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cArr[i][j] == 1) {
					enemy.push_back({ i, j });
				}
			}
		}
	}
	return kill;
}
