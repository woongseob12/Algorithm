#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, H, ans;
pair<int, int> home;
vector<pair<int, int>> pos;
vector<bool> visit;
void init();
void input();
void dfs(pair<int, int> curr, int cnt, int hp);
void solution();

int main() {
	init();
	input();
	solution();
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N >> M >> H;
	int val;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> val;
			if (val == 1) {
				home.first = i;
				home.second = j;
			}
			else if (val == 2) {
				pos.push_back({ i,j });
			}
		}
	}
	visit.resize(pos.size());
}

void solution() {
	dfs(home, 0, M);
	cout << ans << "\n";
}

void dfs(pair<int, int> curr, int cnt, int hp) {
	if (cnt > ans && abs(curr.first - home.first) + abs(curr.second - home.second) <= hp) {
		ans = cnt;
	}
	if (hp <= 0) {
		return;
	}
		
	for (int i = 0; i < pos.size(); i++) {
		int dist = abs(pos[i].first - curr.first) + abs(pos[i].second - curr.second);
		if (dist <= hp && !visit[i]) {
			visit[i] = true;
			dfs(pos[i], cnt + 1, hp - dist + H);
			visit[i] = false;
		}
	}
}