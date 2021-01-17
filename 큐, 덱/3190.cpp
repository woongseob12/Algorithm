#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, K, L;
int map[101][101];
pair<int, int> pos[4] = { {0, 1}, {-1,0}, {0,-1}, {1,0} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		map[r][c] = 1;
	}

	// 방향 전환
	cin >> L;
	vector<pair<int, char>> dir(L);
	for (int i = 0; i < L; i++) {
		cin >> dir[i].first >> dir[i].second;
	}

	pair<int, int> head = { 1,1 };
	deque<pair<int, int>> snake;
	snake.push_back(head);
	int idx = 0, ans = 0;

	while (1){
		ans++;
		head.first += pos[idx].first;
		head.second += pos[idx].second;
		if (head.first > N || head.first<= 0 || head.second > N || head.second <= 0 || map[head.first][head.second] == -1) { break; }

		snake.push_back(head);
		if (map[snake.back().first][snake.back().second] != 1) {
			map[snake.front().first][snake.front().second] = 0;
			snake.pop_front();
		}
		map[snake.back().first][snake.back().second] = -1;
		
		for (int i = 0; i < (int)dir.size(); i++) {
			if (ans  != dir[i].first) { continue; }
			if (dir[i].second == 'L') {
				idx += 1;
				if (idx > 3) { idx -= 4; }
			}
			else {
				idx -= 1;
				if (idx < 0) { idx += 4; }
			}
		}
	}
	cout << ans << '\n';
}

