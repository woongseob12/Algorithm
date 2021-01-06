#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> start(3), curr(3), nextBottle(3);
bool visit[201][201][201];
queue<vector<int>> q;
vector<int> ans;
void bfs();
void MakeEmpty(int from, int to, vector<int> curr);
void MakeFull(int from, int to, vector<int> curr);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> start[0] >> start[1] >> start[2];

	bfs();
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	int ansSize = ans.size();
	for (int i = 0; i < ansSize; ++i) {
		cout << ans[i] << " ";
	}
}

void bfs() {
	q.push({ 0,0,start[2] });
	visit[0][0][start[2]] = true;
	vector<int> curr(3);
	while (!q.empty()) {
		curr[0] = q.front()[0];
		curr[1] = q.front()[1];
		curr[2] = q.front()[2];
		if (curr[0] == 0) { ans.push_back(curr[2]); }
		q.pop();
		for (int i = 0; i < 3; i++) {
			int from = i, to = from + 1;
			if (to > 2) { to -= 3; }
			MakeEmpty(from, to, curr);
			MakeFull(from, to, curr);
			to = from + 2;
			if (to > 2) { to -= 3; }
			MakeEmpty(from, to, curr);
			MakeFull(from, to, curr);
		}
	}
	return;
}

void MakeEmpty(int from, int to, vector<int> curr) {
	vector<int> next = { curr[0],curr[1],curr[2] };
	if (curr[from] != 0 && start[to] - curr[to] >= curr[from]) {
		next[from] = 0;
		next[to] = curr[to] + curr[from];
		if (!visit[next[0]][next[1]][next[2]]) {
			visit[next[0]][next[1]][next[2]] = true;
			q.push(next);
		}
	}
}

void MakeFull(int from, int to, vector<int> curr) {
	vector<int> next = { curr[0],curr[1],curr[2] };
	if (curr[from] != 0 && start[to] - curr[to] <= curr[from]) {
		next[from] = curr[from] - (start[to] - curr[to]);
		next[to] = start[to];
		if(!visit[next[0]][next[1]][next[2]]) {
			visit[next[0]][next[1]][next[2]] = true;
			q.push(next);
		}
	}
}
