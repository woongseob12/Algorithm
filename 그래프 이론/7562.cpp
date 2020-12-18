#include <iostream>
#include <queue>
using namespace std;

int l;
int map[300][300];
bool visit[300][300];
pair<int, int> curr, dest;
pair<int, int> pos[8] = {
	{2,1},{1,2},
	{-1,2},{-2,1},
	{-2,-1},{-1,-2},
	{1,-2},{2,-1}
};
int bfs(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int TC; 
	cin >> TC;
	while (TC--) {
		cin >> l;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				visit[i][j] = false;
			}
		}
		
		cin >> curr.first >> curr.second >> dest.first >> dest.second;
		cout << bfs(curr.first, curr.second) << '\n';
	}
}

int bfs(int x, int y) {
	visit[x][y] = true;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(x, y),0));

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == dest.first && y == dest.second) {
			return cnt;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + pos[i].first, ny = y + pos[i].second;
			if (nx < 0 || nx >= l || ny < 0 || ny >= l) { continue; }
			if (!visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}
	return -1;
}