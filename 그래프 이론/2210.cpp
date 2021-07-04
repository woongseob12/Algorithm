#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int arr[5][5];
set<string> s;
queue<pair<pair<int,int>,string>> q;
void solve();
void input();
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}

void input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			q.push({ { i,j },to_string(arr[i][j]) });
		}
	}
}

void solve() {
	bfs();
	cout << s.size();
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		string curr = q.front().second;
		q.pop();
		if (curr.length() == 6) {
			s.insert(curr);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) { continue; }
			q.push({ {ny,nx}, curr + to_string(arr[ny][nx]) });
		}
	}
}